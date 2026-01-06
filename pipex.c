/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:11:15 by aalmoman          #+#    #+#             */
/*   Updated: 2026/01/06 19:51:53 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(char **av, char **env, int *pipe_fd)
{
	int	input_fd;

	input_fd = open(av[1], O_RDONLY);
	if (input_fd < 0)
	{
		ft_putstr_fd("error ", 2);
		perror(av[1]);
		close_fds(pipe_fd[0], pipe_fd[1]);
		exit(1);
	}
	if (dup2(input_fd, STDIN_FILENO) < 0)
		error();
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
		close_fds_error(pipe_fd[0], pipe_fd[1]);
	close(input_fd);
	close_fds(pipe_fd[0], pipe_fd[1]);
	execute_command(av[2], env);
}

void	second_cmd(char **av, char **env, int *pipe_fd)
{
	int	out_fd;

	out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
	{
		ft_putstr_fd("error ", 2);
		perror(av[4]);
		close_fds(pipe_fd[0], pipe_fd[1]);
		exit(1);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
		error();
	if (dup2(out_fd, STDOUT_FILENO) < 0)
		error();
	close_fds(pipe_fd[0], pipe_fd[1]);
	close(out_fd);
	execute_command(av[3], env);
}

void	ft_pipe(char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	child1;
	pid_t	child2;

	if (!validate_command(av[2], env) || !validate_command(av[3], env))
		exit(1);
	if (pipe(pipe_fd) < 0)
		error();
	child1 = fork();
	if (child1 < 0)
		close_fds_error(pipe_fd[0], pipe_fd[1]);
	if (child1 == 0)
		first_cmd(av, env, pipe_fd);
	child2 = fork();
	if (child2 < 0)
	{
		waitpid(child1, NULL, 0);
		close_fds_error(pipe_fd[0], pipe_fd[1]);
		error();
	}
	if (child2 == 0)
		second_cmd(av, env, pipe_fd);
	close_fds(pipe_fd[0], pipe_fd[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_putstr_fd("Error: invalid arguments \n", 2);
		ft_putstr_fd("IT SHOULD BE LIKE : ./pipex file1 cmd1 cmd2 file2\n", 1);
		return (1);
	}
	ft_pipe(av, env);
	return (0);
}

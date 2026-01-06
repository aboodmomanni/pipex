/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:11:32 by aalmoman          #+#    #+#             */
/*   Updated: 2026/01/04 21:11:32 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(1);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	validate_command(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
		return (0);
	path = absolute_path_checker(args[0], env);
	if (!path)
	{
		ft_putstr_fd("wrong command :( -> ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd("\n", 2);
		free_array(args);
		return (0);
	}
	free(path);
	free_array(args);
	return (1);
}

void	close_fds(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	close_fds_error(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
	error();
}

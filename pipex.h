/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:49:37 by aalmoman          #+#    #+#             */
/*   Updated: 2026/01/06 19:36:31 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

void	error(void);
void	free_array(char **array);
void	close_fds(int fd1, int fd2);
void	close_fds_error(int fd1, int fd2);
char	*check_path(char **env);
char	*join_path(char *dir, char *cmd);
char	*find_path(char *cmd, char **env);
char	*absolute_path_checker(char *cmd, char **env);
void	execute_command(char *cmd_str, char **env);
int		validate_command(char *cmd, char **env);
void	first_cmd(char **av, char **env, int *pipe_fd);
void	second_cmd(char **av, char **env, int *pipe_fd);
void	ft_pipe(char **av, char **env);

#endif

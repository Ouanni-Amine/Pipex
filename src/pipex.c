/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:10:30 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/24 17:20:14 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int fd0, int fd1)
{
	close (fd0);
	close (fd1);
	perror("pipex");
	exit(1);
}

void	ft_parent(int *pipe_fd, int id1, int id2)
{
	int	status;
	int	i;

	i = 1;
	close (pipe_fd[0]);
	close (pipe_fd[1]);
	waitpid(id1, 0, 0);
	waitpid(id2, &status, 0);
	if (WIFEXITED(status))
		i = WEXITSTATUS(status);
	exit(i);
}

void	valid_input(int c)
{
	if (c != 5)
	{
		ft_putstr_fd("pipex: Invalid number of arguments\n", 2);
		exit(1);
	}
}

int	main(int c, char **v, char **env)
{
	int		pipe_fd[2];
	int		pipe_status;
	pid_t	child1_id;
	pid_t	child2_id;

	valid_input(c);
	pipe_status = pipe(pipe_fd);
	if (pipe_status < 0)
	{
		perror("pipex ");
		exit(1);
	}
	child1_id = fork();
	if (child1_id < 0)
		ft_error(pipe_fd[0], pipe_fd[1]);
	if (child1_id == 0)
		handle_first_command(pipe_fd, v, env);
	child2_id = fork();
	if (child2_id < 0)
		ft_error(pipe_fd[0], pipe_fd[1]);
	if (child2_id == 0)
		handle_second_command(pipe_fd, v, env);
	ft_parent(pipe_fd, child1_id, child2_id);
}

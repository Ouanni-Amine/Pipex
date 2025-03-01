/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:29:04 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/25 16:36:57 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	infile_check(char *file)
{
	int	input_fd;

	input_fd = open(file, O_RDONLY);
	if (input_fd < 0)
	{
		perror("pipex");
		exit(1);
	}
	return (input_fd);
}

void	dup_fd(char	*file, int pipe_fd1)
{
	int	input_fd;

	if ((dup2(pipe_fd1, 1)) < 0)
	{
		close (pipe_fd1);
		perror("pipex");
		exit(1);
	}
	close (pipe_fd1);
	input_fd = infile_check(file);
	if ((dup2(input_fd, 0)) < 0)
	{
		close (input_fd);
		perror("pipex");
		exit(1);
	}
	close(input_fd);
}

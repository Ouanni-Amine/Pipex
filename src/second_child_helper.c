/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_child_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:09:50 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/25 16:37:19 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	outfile_check(char *file)
{
	int	output_fd;

	output_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd < 0)
	{
		perror("pipex");
		exit(1);
	}
	return (output_fd);
}

void	dup_fd2(char *file, int pipe_fd0)
{
	int	output_fd;

	if ((dup2(pipe_fd0, 0)) < 0)
	{
		close (pipe_fd0);
		perror("pipex");
		exit(1);
	}
	close (pipe_fd0);
	output_fd = outfile_check(file);
	if ((dup2(output_fd, 1)) < 0)
	{
		close (output_fd);
		perror("pipex");
		exit(1);
	}
	close(output_fd);
}

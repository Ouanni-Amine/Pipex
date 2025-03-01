/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output_handle_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:54:35 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/25 21:13:15 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	normal_inputfd(char **v, int *pipe_fd)
{
	int	input_fd;

	input_fd = open(v[1], O_RDONLY);
	if (input_fd < 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		perror("pipex");
		exit(1);
	}
	return (input_fd);
}

int	normal_outputfd(char **v, int c )
{
	int	output_fd;

	output_fd = open(v[c - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd < 0)
	{
		perror("pipex");
		exit(1);
	}
	return (output_fd);
}

int	heredoc_outputfd(char **v, int c)
{
	int	outputfd;

	outputfd = open(v[c -1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outputfd < 0)
	{
		perror("pipex");
		exit(1);
	}
	return (outputfd);
}

int	fill_tempfile(int input_fd, char *limiter)
{
	char	*line;

	line = NULL;
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_strcmp(line, limiter))
		{
			free(line);
			break ;
		}
		if (write(input_fd, line, ft_strlen(line)) < 0)
		{
			free(line);
			free(limiter);
			perror("pipex");
			return (-1);
		}
		free(line);
	}
	close (input_fd);
	return (1);
}

int	heredoc_inputfd(char **v)
{
	int		input_fd;
	char	*limiter;

	limiter = ft_strjoin(v[2], "\n");
	if (!limiter)
		return (-1);
	input_fd = open("temp.txt", O_WRONLY | O_CREAT, 0644);
	if (input_fd < 0)
	{
		perror("pipex");
		free(limiter);
		return (-1);
	}
	if (fill_tempfile(input_fd, limiter) == -1)
		return (-1);
	free(limiter);
	input_fd = open("temp.txt", O_RDONLY);
	if (input_fd < 0)
	{
		perror("pipex");
		return (-1);
	}
	unlink("temp.txt");
	return (input_fd);
}

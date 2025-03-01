/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:58:55 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/26 16:55:03 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_process_input(t_pipex *data)
{
	if (!data->heredoc)
		data->input_fd = normal_inputfd(data->v, data->pipe_fd);
	if (data->input_fd < 0)
	{
		close (data->pipe_fd[0]);
		close (data->pipe_fd[1]);
		exit(1);
	}
	if (dup2 (data->input_fd, STDIN_FILENO) < 0)
		cleanup_exit_process(data->pipe_fd, data->input_fd, 1);
	close (data->input_fd);
}

void	other_process_input(t_pipex *data, int i)
{
	int	diff;

	diff = i < data->nb_cmd - 1;
	if (dup2(data->prev_fd, STDIN_FILENO) < 0)
		cleanup_exit_process(data->pipe_fd, data->prev_fd, diff);
	close (data->prev_fd);
}

void	last_process_output(t_pipex *data)
{
	if (data->heredoc)
		data->output_fd = heredoc_outputfd(data->v, data->c);
	else
		data->output_fd = normal_outputfd(data->v, data->c);
	if (dup2(data->output_fd, STDOUT_FILENO) < 0)
		cleanup_exit_process(data->pipe_fd, data->output_fd, 0);
	close (data->output_fd);
}

void	other_process_output(t_pipex *data)
{
	if (dup2 (data->pipe_fd[1], STDOUT_FILENO) < 0)
		cleanup_exit_process(data->pipe_fd, -1, 1);
	close (data->pipe_fd[0]);
	close (data->pipe_fd[1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:34:40 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/26 17:05:24 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	childs_process(t_pipex *data, int i)
{
	if (i == 0)
		first_process_input(data);
	else
		other_process_input(data, i);
	if (i == data->nb_cmd -1)
		last_process_output(data);
	else
		other_process_output(data);
	execute_cmd(data->v[data->cmd_start + i], data->env, i == data->nb_cmd - 1);
}

void	parent_process(t_pipex *data, int i)
{
	if (data->heredoc && data->input_fd > -1)
	{
		close(data->input_fd);
		data->input_fd = -1;
	}
	if (data->prev_fd != STDIN_FILENO)
		close(data->prev_fd);
	if (i < data->nb_cmd - 1)
	{
		close (data->pipe_fd[1]);
		data->prev_fd = data->pipe_fd[0];
	}
	data->last_pid = data->pid;
}

void	parent_exit(t_pipex *data)
{
	int	i;
	int	wpid;
	int	target_status;
	int	status;

	i = 0;
	target_status = 1;
	while (i < data->nb_cmd)
	{
		wpid = wait(&status);
		if (wpid == data->last_pid && WIFEXITED(status))
			target_status = WEXITSTATUS(status);
		i++;
	}
	exit(target_status);
}

void	pipex_logique(t_pipex *data)
{
	int	i;
	int	diff;

	i = 0;
	data->prev_fd = STDIN_FILENO;
	while (i < data->nb_cmd)
	{
		diff = i < data->nb_cmd - 1;
		if (diff)
		{
			if (pipe(data->pipe_fd) < 0)
				cleanup_exit_process(data->pipe_fd, data->prev_fd, 0);
		}
		data->pid = fork();
		if (data->pid < 0)
			cleanup_exit_process(data->pipe_fd, data->prev_fd, diff);
		if (data->pid == 0)
			childs_process(data, i);
		else
			parent_process(data, i);
		i++;
	}
	parent_exit(data);
}

int	main(int c, char **v, char **env)
{
	t_pipex	data;

	valid_input(c, 5);
	data.heredoc = heredoc_check(v[1]);
	data.v = v;
	data.c = c;
	data.env = env;
	if (data.heredoc)
	{
		valid_input(c, 6);
		data.input_fd = heredoc_inputfd(v);
		data.nb_cmd = c - 4;
		data.cmd_start = 3;
	}
	else
	{
		data.nb_cmd = c - 3;
		data.cmd_start = 2;
	}
	pipex_logique(&data);
}

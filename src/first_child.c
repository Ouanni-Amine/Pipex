/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:14:54 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/26 15:58:18 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*command_founder(char **env, char **cmd_args)
{
	if (ft_strchr(cmd_args[0], '/'))
		return (command_with_path(cmd_args, 1));
	else
		return (command_without_path(env, cmd_args, 1));
}

void	handle_first_command(int *pipe_fd, char **v, char **env)
{
	char	*cmd_path;
	char	**cmd_args;

	close (pipe_fd[0]);
	dup_fd(v[1], pipe_fd[1]);
	cmd_args = ft_split(v[2], '\0');
	if (!cmd_args || !cmd_args[0])
	{
		ft_putstr_fd("pipex:command not found\n", 2);
		cleanup_exit(NULL, NULL, cmd_args, 1);
	}
	cmd_path = command_founder(env, cmd_args);
	execve(cmd_path, cmd_args, env);
	perror("pipex");
	cleanup_exit(cmd_path, NULL, cmd_args, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_cmd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:03 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/26 15:58:45 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*command_without_path2(char **args, char **solo, char *cmd_s, int exit)
{
	char	*res;
	int		i;

	i = 0;
	while (solo[i])
	{
		res = ft_strjoin(solo[i], cmd_s);
		if (!res)
			cleanup_exit(cmd_s, solo, args, 1);
		if (access(res, X_OK) == 0)
			break ;
		free(res);
		i++;
	}
	free(cmd_s);
	if (!solo[i])
	{
		ft_putstr_fd("pipex:command not found\n", 2);
		cleanup_exit(NULL, solo, args, exit);
	}
	ft_free_split(solo);
	return (res);
}

char	*command_without_path(char **env, char **cmd_args, int exit)
{
	char	*cmd_slash;
	char	*path_env;
	char	**path_solo;
	int		i;

	i = check_path(env, cmd_args);
	cmd_slash = ft_strjoin("/", cmd_args[0]);
	if (!cmd_slash)
		cleanup_exit(NULL, NULL, cmd_args, 1);
	path_env = ft_strtrim(env[i], "PATH=");
	if (!path_env)
		cleanup_exit(cmd_slash, NULL, cmd_args, 1);
	path_solo = ft_split(path_env, ':');
	if (!path_solo)
	{
		free(cmd_slash);
		cleanup_exit(path_env, NULL, cmd_args, 1);
	}
	free(path_env);
	return (command_without_path2(cmd_args, path_solo, cmd_slash, exit));
}

char	*command_with_path(char **cmd_args, int exit)
{
	char	*res;

	if (access(cmd_args[0], X_OK) != 0)
	{
		perror("pipex");
		cleanup_exit(NULL, NULL, cmd_args, exit);
	}
	res = ft_strdup(cmd_args[0]);
	if (!res)
		cleanup_exit(NULL, NULL, cmd_args, 1);
	return (res);
}

char	*command_founder(char **env, char **cmd_args, int exit_code)
{
	if (ft_strchr(cmd_args[0], '/'))
		return (command_with_path(cmd_args, exit_code));
	else
		return (command_without_path(env, cmd_args, exit_code));
}

void	execute_cmd(char *cmd, char **env, int is_last_cmd)
{
	char	*cmd_path;
	char	**cmd_args;
	int		exit_code;

	if (is_last_cmd)
		exit_code = 127;
	else
		exit_code = 1;
	cmd_args = ft_split(cmd, '\0');
	if (!cmd_args || !cmd_args[0])
	{
		ft_putstr_fd("pipex:command not found\n", 2);
		cleanup_exit(NULL, NULL, cmd_args, exit_code);
	}
	cmd_path = command_founder(env, cmd_args, exit_code);
	execve(cmd_path, cmd_args, env);
	perror("pipex");
	cleanup_exit(cmd_path, NULL, cmd_args, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:46:25 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/25 18:13:13 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	valid_input(int c, int num)
{
	if (c < num)
	{
		ft_putstr_fd("pipex:Invalid number of arguments\n", 2);
		exit(1);
	}
}

void	cleanup_exit_process(int *pipe_fd, int prev_fd, int pipe_created)
{
	if (prev_fd > -1 && prev_fd != STDIN_FILENO)
		close (prev_fd);
	if (pipe_created)
	{
		close(pipe_fd[1]);
		close(pipe_fd[0]);
	}
	perror("pipex");
	exit(1);
}

int	heredoc_check(char *str)
{
	if (ft_strcmp(str, "here_doc") == 0)
		return (1);
	return (0);
}

void	ft_free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	cleanup_exit(char *v1, char **v2, char **v3, int exit_code)
{
	if (v1)
		free(v1);
	if (v2)
		ft_free_split(v2);
	if (v3)
		ft_free_split(v3);
	exit(exit_code);
}

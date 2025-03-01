/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cleanup2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:24:52 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/25 16:25:34 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	check_path(char **env, char **cmd_args)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			break ;
		i++;
	}
	if (env[i] == NULL)
	{
		ft_putstr_fd("pipex:PATH environment variable not found\n", 2);
		cleanup_exit(NULL, NULL, cmd_args, 1);
	}
	return (i);
}

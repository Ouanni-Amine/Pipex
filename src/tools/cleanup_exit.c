/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:34:55 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/25 16:37:33 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

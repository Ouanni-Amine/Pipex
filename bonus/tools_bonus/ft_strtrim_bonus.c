/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:13:43 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/25 16:14:01 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static int	start(const char *s, const char*s1)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (s[i] != '\0')
	{
		while (s1[j] != '\0')
		{
			if (s[i] == s1[j])
			{
				i++;
				j = 0;
			}
			else
				j++;
		}
	}
	return (i);
}

static int	end(const char *s, const char*s1)
{
	int	y;
	int	k;

	y = 0;
	k = (ft_strlen(s) - 1);
	while (s1[y] != '\0')
	{
		if (k < 0)
			return (k);
		if (s[k] == s1[y])
		{
			k--;
			y = 0;
		}
		else
			y++;
	}
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		m;
	char	*p;
	int		o;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = start(s1, set);
	j = end(s1, set);
	m = 0;
	o = (j + 1) - i;
	if (i > j)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (o + 1));
	if (p == NULL)
		return (NULL);
	while (m < o)
		p[m++] = s1[i++];
	p[m] = '\0';
	return (p);
}

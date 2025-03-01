/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:09:09 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/17 15:08:20 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*fill(const char *s, char *p)
{
	while (*s != '\0')
	{
		*p = *s;
		p++;
		s++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*p;
	char	*r;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (s1len + s2len +1));
	if (p == NULL)
		return (NULL);
	r = p;
	p = fill(s1, p);
	p = fill(s2, p);
	*p = '\0';
	return (r);
}

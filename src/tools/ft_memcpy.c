/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:09:54 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/17 17:56:44 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	unsigned char		*p1;

	i = 0;
	if (dst == src)
		return (dst);
	p = (const unsigned char *)src;
	p1 = (unsigned char *)dst;
	while (i < n)
	{
		p1[i] = p [i];
		i++;
	}
	return (dst);
}

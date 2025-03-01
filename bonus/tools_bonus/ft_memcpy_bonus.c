/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:09:22 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/25 16:16:17 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

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

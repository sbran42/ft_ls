/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:17:55 by sbran             #+#    #+#             */
/*   Updated: 2015/03/02 18:22:47 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)(unsigned long)src;
	b = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return ((void *)dst);
}

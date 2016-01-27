/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:17:49 by sbran             #+#    #+#             */
/*   Updated: 2015/03/02 18:22:41 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*a;
	const char	*b;

	b = src;
	a = dst;
	while (n--)
	{
		if (*b == c)
		{
			*a++ = *b++;
			return (a);
		}
		*a++ = *b++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:19:51 by sbran             #+#    #+#             */
/*   Updated: 2015/03/04 16:17:05 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			d;
	size_t			s;
	size_t			o;

	o = size;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (!size)
		return (o + s);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (d + s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:25:27 by sbran             #+#    #+#             */
/*   Updated: 2016/01/11 19:25:29 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			s;
	size_t			o;

	o = size;
	s = ft_strlen(src);
	if (!size)
		return (o + s);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:18:22 by sbran             #+#    #+#             */
/*   Updated: 2015/03/02 18:22:51 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;

	if ((!src) || (src == dst))
		return (dst);
	str = ft_memalloc(sizeof(unsigned char *) * len);
	str = ft_memcpy(str, src, len);
	dst = ft_memcpy(dst, str, len);
	free((void *)str);
	return (dst);
}

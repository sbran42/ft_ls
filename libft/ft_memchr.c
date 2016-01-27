/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:17:51 by sbran             #+#    #+#             */
/*   Updated: 2015/03/02 18:22:43 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				a;
	int				i;
	unsigned char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char *)(unsigned long)s;
	a = c;
	while ((i < (int)n))
	{
		if (str[i] == a)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

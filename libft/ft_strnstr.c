/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:20:10 by sbran             #+#    #+#             */
/*   Updated: 2015/03/04 16:17:39 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	c;
	char	sc;
	size_t	len;
	int		go;

	go = 0;
	if ((c = *s2++) != '\0')
	{
		len = ft_strlen(s2);
		while (!go || ft_strncmp(s1, s2, len) != 0)
		{
			go = 1;
			if ((sc = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (sc != c)
			{
				if ((sc = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (len > n)
				return (NULL);
		}
		s1--;
	}
	return ((char *)(unsigned long)s1);
}

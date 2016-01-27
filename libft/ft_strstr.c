/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:20:18 by sbran             #+#    #+#             */
/*   Updated: 2015/03/04 16:17:54 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	k;
	int	j;
	int	l;

	i = -1;
	j = (int)ft_strlen(s2);
	if (s2 == NULL || s2[0] == '\0')
		return ((char *)(unsigned long)s1);
	l = 0;
	while (s1[++i] != '\0')
		if (s1[i] == s2[0])
		{
			l = i;
			k = 0;
			while (s1[l] == s2[k])
			{
				if (k == (j - 1))
					return ((char *)(unsigned long)s1 + i);
				l++;
				k++;
			}
		}
	return (NULL);
}

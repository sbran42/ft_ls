/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:17:53 by sbran             #+#    #+#             */
/*   Updated: 2015/03/04 16:19:30 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)(unsigned long)s1;
	str2 = (char *)(unsigned long)s2;
	if ((str1 == NULL) || (str2 == NULL) || ((int)n == 0))
		return (0);
	while ((i < (int)n - 1) || (i == 0))
	{
		if ((str1[i]) == (str2[i]))
			i++;
		else
			return ((str2[0] != '\0') ? (str1[i]) - (str2[i]) : 200);
	}
	return (0);
}

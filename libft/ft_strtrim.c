/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:20:22 by sbran             #+#    #+#             */
/*   Updated: 2015/03/21 14:10:20 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	ft_strtrimback(const char *s)
{
	unsigned	i;

	i = 0;
	while (s[i + 1] != '\0')
		i++;
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && (i))
		i--;
	return (i);
}

char			*ft_strtrim(const char *s)
{
	unsigned	v;
	unsigned	k;
	unsigned	i;
	char		*str;

	if (s)
	{
		i = (unsigned)ft_strlen(s);
		v = ft_strtrimback(s);
		str = ft_memalloc(i);
		i = 0;
		k = 0;
		while (s[i] != '\0' && (s[i] == ' ' || (s[i] == '\n' || s[i] == '\t')))
			i++;
		while (i <= v)
			str[k++] = s[i++];
		str[k] = '\0';
		return (str);
	}
	return (0);
}

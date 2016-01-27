/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:20:20 by sbran             #+#    #+#             */
/*   Updated: 2015/03/04 16:18:04 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (s)
	{
		str = ft_memalloc(len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while ((s[start] != '\0') && (i < len))
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:19:55 by sbran             #+#    #+#             */
/*   Updated: 2015/03/04 16:17:12 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = (int)ft_strlen(s);
	str = ft_memalloc((size_t)i + 1);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}

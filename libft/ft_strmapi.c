/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:19:58 by sbran             #+#    #+#             */
/*   Updated: 2015/03/04 16:17:16 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned		i;
	char			*str;

	i = (unsigned)ft_strlen(s);
	str = ft_memalloc((size_t)i);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = ((*f)(i, s[i]));
		i++;
	}
	return (str);
}

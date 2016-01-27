/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:19:49 by sbran             #+#    #+#             */
/*   Updated: 2015/03/28 23:04:33 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				k;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] != '\0')
		str[k++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[k++] = s2[i++];
	str[k] = '\0';
	return (str);
}

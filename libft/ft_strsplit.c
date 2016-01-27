/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:20:16 by sbran             #+#    #+#             */
/*   Updated: 2015/03/04 16:23:05 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_wordlen(char const *s, char c, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		j++;
		i++;
	}
	return (j - 1);
}

static unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 1;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i - 1] == c))
			j++;
		i++;
	}
	return (j);
}

char				**ft_strsplit(char const *s, char c)
{
	int				i;
	char			**tab;
	unsigned int	len;
	int				j;

	i = -1;
	j = 0;
	if (s)
	{
		if ((tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1)))
				== NULL)
			return (NULL);
		while (s[++i] != '\0')
		{
			(s[i] == '\n') ? i++ : i;
			if (s[i] != c)
			{
				len = ft_wordlen(s, c, (unsigned)i);
				tab[j++] = ft_strsub(s, (unsigned)i, (len + 1));
				i += len;
			}
		}
		return (tab);
	}
	return (0);
}

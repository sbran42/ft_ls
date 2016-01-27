/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 15:53:57 by sbran             #+#    #+#             */
/*   Updated: 2014/10/05 20:03:12 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ft_reverse(char **arg, int test)
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < test)
	{
		tmp = arg[test];
		arg[test] = arg[i];
		arg[i] = tmp;
		test--;
	}
	return (arg);
}

char		**ft_sort_r(int test, char **ls)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	while (i < test - 1)
	{
		count = i;
		while (count >= 0 && ft_strcmp(ls[count], ls[count + 1]) > 0)
		{
			tmp = ls[count + 1];
			ls[count + 1] = ls[count];
			ls[count] = tmp;
			--count;
		}
		i++;
	}
	return (ls);
}

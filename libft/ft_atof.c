/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 17:10:40 by sbran             #+#    #+#             */
/*   Updated: 2015/04/01 23:25:52 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static double	atoi_double(char *str, double ret, int signe)
{
	double	index;
	double	tmp;

	index = 10;
	if (*str == '.' || *str == ',')
		str++;
	while ((*str >= '0' && *str <= '9'))
	{
		tmp = (*str++ - '0');
		tmp /= index;
		ret += tmp;
		index *= 10;
	}
	return (ret * signe);
}

double			ft_atof(const char *str)
{
	double		ret;
	int			signe;

	ret = 0;
	if (!str)
		return (ret);
	signe = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
			|| *str == '\r' || *str == '\v' || *str == '0')
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0' && *str <= '9'))
		ret = ret * 10 + (*str++ - '0');
	if (*str == '.' || *str == ',')
		return (atoi_double((char*)(unsigned long)str, ret, signe));
	return (ret * signe);
}

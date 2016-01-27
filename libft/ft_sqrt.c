/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 16:50:34 by sbran             #+#    #+#             */
/*   Updated: 2015/04/02 17:46:25 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_sqrt(int nb)
{
	double		result;
	double		diff;

	if ((double)nb == 0.0 || (double)nb == 1.0)
		return ((double)nb);
	result = (double)nb;
	diff = result;
	result = 0.5 * (result + (double)nb / result);
	while (result != diff)
	{
		diff = result;
		result = 0.5 * (result + (double)nb / result);
	}
	return (result);
}

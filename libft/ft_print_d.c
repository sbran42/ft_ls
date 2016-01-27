/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 20:04:14 by sbran             #+#    #+#             */
/*   Updated: 2015/04/01 21:27:50 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_d(va_list ap)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	count = va_arg(ap, int);
	ft_putnbr(count);
	if (count == 0)
		return (0);
	if (count % 2147483648 == 0)
		i = 9;
	if (count < 0)
	{
		count *= -1;
		i++;
	}
	while ((count /= 10) > 0)
		i++;
	return (i);
}

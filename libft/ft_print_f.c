/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 22:27:20 by sbran             #+#    #+#             */
/*   Updated: 2015/04/02 17:18:09 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_f(va_list ap)
{
	double	count;
	int		i;

	count = va_arg(ap, double);
	if (count < 0)
		ft_putchar('-');
	count = (count < 0) ? -count : count;
	ft_putstr(ft_itoa((int)count));
	ft_putchar('.');
	count -= (int)count;
	i = -1;
	while (count - (int)count > 0.00001f && ++i < 5)
	{
		if ((int)(count * 10.0f) % 10 == 0)
			ft_putchar('0');
		count *= 10;
	}
	ft_putstr(ft_itoa((int)count));
	return (0);
}

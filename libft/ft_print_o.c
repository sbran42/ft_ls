/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:28:58 by sbran             #+#    #+#             */
/*   Updated: 2015/04/01 21:27:46 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_o(va_list ap)
{
	long	count;
	int		i;
	int		count_car;
	int		*str;

	count = 0;
	i = 0;
	count_car = 0;
	str = (int *)malloc(sizeof(int) * 11);
	count = va_arg(ap, long);
	if (count < 0)
		count = 37777777775 + count;
	while (count != 0 || i == 0)
	{
		str[i++] = count % 8;
		count /= 8;
	}
	count_car = i--;
	while (i-- >= 0)
		ft_putnbr(str[i + 1]);
	free(str);
	return (count_car - 1);
}

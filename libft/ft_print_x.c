/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:53:26 by sbran             #+#    #+#             */
/*   Updated: 2015/04/01 21:27:33 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_x(va_list ap)
{
	long	count;
	int		i;
	int		j;
	char	*str;
	char	str_final[15];

	count = 0;
	j = 0;
	str = "0123456789abcdef";
	count = va_arg(ap, long);
	i = 0;
	while (count != 0 || i == 0)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (count % 16 == i++)
				str_final[j++] = str[i - 1];
		}
		count /= 16;
	}
	count = j--;
	while (j >= 0)
		ft_putchar(str_final[j--]);
	return ((int)count - 1);
}

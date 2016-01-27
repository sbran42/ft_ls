/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 19:39:36 by sbran             #+#    #+#             */
/*   Updated: 2015/04/01 21:27:43 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_hexa(size_t p)
{
	size_t	count;
	size_t	i;
	int		j;
	char	*str;
	char	str_final[15];

	count = 0;
	j = 0;
	str = "0123456789abcdef";
	count = p;
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
	count = (size_t)j--;
	while (j >= 0)
		ft_putchar(str_final[j--]);
	return ((int)count + 1);
}

int			ft_print_p(va_list ap)
{
	size_t	p;

	p = va_arg(ap, size_t);
	ft_putstr("0x");
	return (ft_put_hexa(p));
}

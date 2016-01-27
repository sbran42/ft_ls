/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:44:32 by sbran             #+#    #+#             */
/*   Updated: 2015/04/01 22:38:09 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_flags		g_flags[] = {
	{'s', &ft_print_s},
	{'d', &ft_print_d},
	{'i', &ft_print_d},
	{'-', &ft_print_d},
	{'+', &ft_print_d},
	{'-', &ft_print_d},
	{'#', &ft_print_d},
	{'u', &ft_print_u},
	{'c', &ft_print_c},
	{'o', &ft_print_o},
	{'x', &ft_print_x},
	{'p', &ft_print_p},
	{'f', &ft_print_f},
	{0, NULL}
};

static int		ft_test(va_list ap, char *str, int car)
{
	int		i;

	i = -1;
	while (g_flags[++i].flag != 0)
	{
		if (g_flags[i].flag == str[car])
		{
			g_flags[i].p(ap);
			break ;
		}
	}
	return (0);
}

static int		ft_pourcent_car(va_list ap, char *str, int car)
{
	int		len;
	int		len2;

	len = 0;
	len2 = 0;
	if (str[car + 1] == '%')
		ft_putchar(37);
	else
	{
		len = ft_test(ap, str, car + 1);
		if (len == -2)
			return (len);
		len2 += len;
	}
	return (len2);
}

static int		ft_len_str(va_list ap, char *str, int car, int len2)
{
	int		len;

	len = 0;
	len = ft_pourcent_car(ap, str, car);
	if (len == -2)
	{
		ft_putstr("(null)");
		len2 += 7;
	}
	len2 += len;
	return (len2);
}

int				ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		car;
	int		len2;

	i = 0;
	car = 0;
	len2 = 0;
	va_start(ap, str);
	while (str[car] != '\0')
	{
		if (str[car] == '%')
		{
			car++;
			if (str[car] == ' ')
				ft_putchar(str[car++]);
			len2 = ft_len_str(ap, (char *)(size_t)str, car - 1, len2);
			i++;
		}
		else
			write(1, &str[car], 1);
		car++;
	}
	va_end(ap);
	return (len2 + car - i);
}

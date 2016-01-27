/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 14:37:31 by sbran             #+#    #+#             */
/*   Updated: 2015/04/01 21:27:36 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_u(va_list ap)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	count = va_arg(ap, size_t);
	ft_putnbr_u((unsigned)count);
	if (count == 0)
		return (0);
	while ((count /= 10) > 0)
	{
		i++;
	}
	return (i);
}

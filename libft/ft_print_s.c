/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 20:04:29 by sbran             #+#    #+#             */
/*   Updated: 2015/04/01 21:27:39 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_s(va_list ap)
{
	char	*contain;

	contain = va_arg(ap, char *);
	if (!contain)
		return (-2);
	ft_putstr(contain);
	if (!ft_strncmp(contain, "", 1))
		return (-1);
	else if (!ft_strncmp(contain, " ", (size_t)ft_strlen(contain)))
		return (0);
	return ((int)ft_strlen(contain + 1));
}

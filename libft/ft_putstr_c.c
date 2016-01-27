/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:23:52 by sbran             #+#    #+#             */
/*   Updated: 2015/04/01 19:55:22 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_c(char *color, char *str, char *end)
{
	char	*final;

	final = malloc(sizeof(char) *
		(ft_strlen(color) + ft_strlen(str) + ft_strlen(end)));
	ft_strcpy(final, color);
	ft_strcat(final, str);
	ft_strcat(final, end);
	ft_putstr(final);
	return (0);
}

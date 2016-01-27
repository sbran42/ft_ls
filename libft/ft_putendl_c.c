/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 19:16:24 by sbran             #+#    #+#             */
/*   Updated: 2016/01/02 19:16:26 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_c(char *color, char *str, char *end)
{
	char	*final;

	final = malloc(sizeof(char) *
		(ft_strlen(color) + ft_strlen(str) + ft_strlen(end)));
	ft_strcpy(final, color);
	ft_strcat(final, str);
	ft_strcat(final, end);
	ft_putendl(final);
	return (0);
}

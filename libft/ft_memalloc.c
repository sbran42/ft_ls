/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:17:46 by sbran             #+#    #+#             */
/*   Updated: 2015/03/02 18:22:36 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;
	unsigned int	counter;
	char			*str;

	counter = 0;
	if (!(mem = (void *)malloc(sizeof(size))))
		return (NULL);
	str = (char *)mem;
	if (mem != NULL)
	{
		while (counter++ < size)
			*str++ = 0;
	}
	return (mem);
}

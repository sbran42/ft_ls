/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:17:23 by sbran             #+#    #+#             */
/*   Updated: 2015/03/02 18:22:24 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*later;

	if (alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			later = tmp->next;
			(*del)(tmp->content, tmp->content_size);
			tmp = later;
		}
		free(*alst);
		*alst = NULL;
	}
}

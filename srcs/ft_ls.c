/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 15:51:35 by sbran             #+#    #+#             */
/*   Updated: 2015/12/30 15:51:38 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_arg(char *av, int num, t_env *env)
{
	static int	count = 0;

	if (env->nb_fold > 1 && (env->op_active.rec == false) && count > 0)
	{
		if (num > 0)
			write(1, "\n", 1);
		ft_putstr_c(C_46, av, C_END);
		ft_putstr_c(C_46, ":\n", C_END);
	}
	++count;
}

int				ft_ls(char *av, t_env *env)
{
	DIR			*dir;
	static int	num = 0;

	if (!(dir = opendir(av)))
	{
		if (env->op_active.rec == false)
		{
			if (errno != 2)
				ft_putendl_c(C_46, av, C_END);
			// else
			// 	ft_printf("ft_ls: %s: No such file or directory\n", av);
		}
		return (0);
	}
	ft_print_arg(av, num, env);
	env->ls = ft_init_f(av, env);
	env->av = av;
	if (env->op_active.rec == false)
		ft_print(env->ls, env);
	++num;
	return (1);
}

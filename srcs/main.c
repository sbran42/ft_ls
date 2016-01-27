/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/01 12:59:53 by sbran             #+#    #+#             */
/*   Updated: 2014/10/05 19:59:53 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_concat(int ac, char **av, t_env *env)
{
	int			i;
	int			j;
	int			count;
	static char	str[0xf00];

	i = 0;
	count = -1;
	while (++i < ac)
	{
		j = -1;
		if (av[i][0] == '-')
			++(env->nb_op);
		while (av[i][++j])
			str[++count] = av[i][j];
		str[++count] = ' ';
	}
	env->nb_fold = (i - 1) - env->nb_op;
	env->args = ft_strdup(str);
}

static void	ft_op(t_env *env)
{
	int			i;
	int			j;
	static char	buf[0xf00];

	i = 0;
	j = -1;
	if (env->args[0] != '-')
		return ;
	while (env->args[i] && env->args[i] == '-' && ++i)
	{
		if (env->args[i] && env->args[i] == '-')
			exit(ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls  [file ...]\n",
		env->args[i]));
		while (env->args[i] && env->args[i] != ' ')
		{
			if (env->args[i] == 'Z' || env->args[i] == '-')
			exit(ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls  %s\n",
		env->args[i], "[file ...]"));
			buf[++j] = env->args[i];
			buf[j + 1] = '\0';
			++i;
		}
		++i;
	}
	env->op = ft_strdup(buf);
}

static void	ft_check_op(t_env *env)
{
	int		i;

	i = -1;
	while (env->op[++i])
	{
		if (env->op[i] == 'a')
			env->op_active.a = true;
		if (env->op[i] == 'r')
			env->op_active.rev = true;
		if (env->op[i] == 'R')
			env->op_active.rec = true;
		if (env->op[i] == 'l')
			env->op_active.l = true;
		if (env->op[i] == 't')
			env->op_active.t = true;
		if (env->op[i] == 'G')
			env->op_active.g = true;
	}
}

static void	ft_in(t_env *env)
{
	env->op_active.a = false;
	env->op_active.rev = false;
	env->op_active.rec = false;
	env->op_active.l = false;
	env->op_active.t = false;
	env->op_active.g = false;
	env->nb_op = 0;
	env->av = NULL;
}

int			main(int ac, char **av)
{
	int		i;
	t_env	env;

	ft_in(&env);
	env.ac = ac;
	if (ac > 1)
	{
		ft_concat(ac, av, &env);
		ft_op(&env);
		if (av[1][0] == '-')
			ft_check_op(&env);
	}
	if (!env.nb_fold)
	{
		if (ft_ls(".", &env) && env.op_active.rec == true)
			ft_rec(".", &env, env.ls);
		return (0);
	}
	if (env.op_active.t)
		av = ft_lt_fold(av, &env);
	i = (env.op_active.rev ? env.nb_op : ac);
	while (av[i = (env.op_active.rev ? i + 1 : i - 1)] && i > env.nb_op)
	{
		// ft_printf("", av[i]);
		ft_ls(av[i], &env);
		if (env.op_active.rec == true)
			ft_rec(av[i], &env, env.ls);
	}
	return (0);
}

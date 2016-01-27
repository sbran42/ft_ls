/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:58:20 by sbran             #+#    #+#             */
/*   Updated: 2015/12/30 16:58:23 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_max(char **ls)
{
	int		max;

	max = 0;
	while (ls[max])
		++max;
	return (max);
}

static int	*ft_sort_init(char **ls, t_env *env, int fold)
{
	struct stat	sb_1;
	char		buf[0xf000];
	int			*timet;
	int			i;

	timet = (int *)malloc(sizeof(int) * env->max);
	i = -1;
	// ft_printf("%s, %d\n", ls[0], i);
	while (++i < env->max)
	{
		// ft_putendl(env->av);
		if (fold == 1)
		{
			lstat(ls[i], &sb_1);
		}
		else
		{
			// ft_putendl(env->av);
			ft_strlcpy(buf, env->av, sizeof(buf));
			ft_strlcat(buf, ls[i], sizeof(buf));
			lstat(buf, &sb_1);
		}
		timet[i] = sb_1.st_mtime;
	}
	return (timet);
}

static int	*ft_sort_init_f(char **ls, t_env *env, int fold)
{
	struct stat	sb_1;
	int			*timet;
	int			i;

	timet = (int *)malloc(sizeof(int) * fold);
	i = env->nb_op;
	while (++i < env->nb_fold + env->nb_op + 1)
	{
		timet[i - env->nb_op - 1] = (stat(ls[i], &sb_1) < 0) ? 2147483647 : sb_1.st_mtime;
		// timet[i - env->nb_op - 1] = sb_1.st_mtime;
		// ft_printf("%s\t%d\t%d\n", ls[i], timet[i - env->nb_op - 1], i - env->nb_op - 1);
	}
	return (timet);
}

char		**ft_lt(char **ls, t_env *env)
{
	int			i;
	int			test;
	char		*tmp;
	int			*timet;
	int			count;

	env->max = ft_max(ls);
	timet = ft_sort_init(ls, env, 0);
	i = -1;
	while (++i < env->max - 1)
	{
		test = i + 1;
		while (--test >= 0 && (timet[test] < timet[test + 1]))
		{
			count = timet[test + 1];
			tmp = ls[test + 1];
			ls[test + 1] = ls[test];
			timet[test + 1] = timet[test];
			ls[test] = tmp;
			timet[test] = count;
		}
	}
	return (ls);
}

char		**ft_lt_fold(char **ls, t_env *env)
{
	int			i;
	int			test;
	char		*tmp;
	int			*timet;
	int			count;

	timet = ft_sort_init_f(ls, env, env->nb_fold);
	i = env->nb_op;
	while (++i < env->nb_fold + env->nb_op + 1)
	{
		test = i - env->nb_op - 1;
		// ft_printf("%s => %d\n", ls[i], timet[i]);
			// ft_printf("%s, %d\t%d\n", ls[test + env->nb_op + 1], timet[test], test);
		while (--test >= 0 && (timet[test] < timet[test + 1]))
		{
			count = timet[test + 1];
			tmp = ls[test + 1 + env->nb_op + 1];
			ls[test + 1 + env->nb_op + 1] = ls[test + env->nb_op + 1];
			timet[test + 1] = timet[test];
			ls[test + env->nb_op + 1] = tmp;
			timet[test] = count;
		}
	}
	return (ls);
}

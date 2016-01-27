/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 15:26:19 by sbran             #+#    #+#             */
/*   Updated: 2016/01/02 15:26:21 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**ft_a(DIR *dir, t_env *env)
{
	static char		*buf[0xf0000];
	char			**ls;
	struct dirent	*direct;
	int				i;

	env->test = 0;
	if (env->op_active.a)
		while ((direct = readdir(dir)))
			buf[env->test++] = ft_strdup(direct->d_name);
	else
		while ((direct = readdir(dir)))
			if (direct->d_name[0] != '.')
				buf[env->test++] = ft_strdup(direct->d_name);
	ls = (char **)malloc(sizeof(char *) * (unsigned long)(env->test) + 1);
	ls[env->test] = NULL;
	i = -1;
	env->nb_elem = env->test - 1;
	while (++i < env->test)
		ls[i] = buf[i];
	ls[i] = NULL;
	return (ls);
}

char		**ft_init_f(char *av, t_env *env)
{
	char			**ls;
	DIR				*dir;

	if (!(dir = opendir(av)))
		return (NULL);
	env->av = ft_strjoin(av, "/");
	ls = ft_a(dir, env);
	closedir(dir);
	if (env->op_active.t == false)
	{
		if (env->op_active.rev == true)
			return (ft_reverse(ft_sort_r(env->test, ls), env->nb_elem));
		else
			return (ft_sort_r(env->test, ls));
	}
	else
	{
		ft_lt(ls, env);
		if (env->op_active.rev == true)
			return (ft_reverse(ls, env->nb_elem));
		else
			return (ls);
	}
}

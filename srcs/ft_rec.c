/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:50:04 by sbran             #+#    #+#             */
/*   Updated: 2015/12/30 18:50:09 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_check(char *av)
{
	DIR				*dir;
	int				i;

	if (!(dir = opendir(av)))
	{
		if (errno == 13)
		{
			ft_putstr("ft_ls: ");
			i = ft_strlen(av);
			while (i >= 0 && av[i] != '/')
				--i;
			ft_printf("%s: ", &av[i + 1]);
			perror("");
		}
		return (0);
	}
	closedir(dir);
	return (1);
}

static void		ft_print_arg(char *av, long count, t_env *env)
{
	if (count > 0 || (count == 0 && env->nb_fold > 1))
	{
		if (count > 0)
			write(1, "\n", 1);
		ft_putstr_c(C_46, av, C_END);
		ft_putstr_c(C_46, ":\n", C_END);
	}
	env->av = av;
}

int				ft_rec(char *av, t_env *env, char **ls)
{
	int				i;
	int				j;
	static long		count = 0;
	char			buf2[0xF000];

	j = -1;
	if (!ft_check(av))
		return (0);
	ft_print_arg(av, count, env);
	i = ft_print(ls, env);
	++count;
	while (++j < i)
	{
		ft_strlcpy(buf2, av, sizeof(buf2));
		ft_strlcat(buf2, "/", sizeof(buf2));
		ft_strlcat(buf2, ls[j], sizeof(buf2));
		if (ft_strcmp(ls[j], "..") && ft_strcmp(ls[j], "."))
			ft_rec(buf2, env, ft_init_f(buf2, env));
	}
	return (0);
}

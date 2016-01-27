/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 15:27:10 by sbran             #+#    #+#             */
/*   Updated: 2016/01/10 14:48:53 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int				ft_nblocks(char **ls, t_env *env)
{
	int					i;
	struct stat			blocks;
	long double			n_b;
	static char			buf2[0xF000];

	i = -1;
	n_b = 0;
	while (ls[++i])
	{
		ft_strlcpy(buf2, env->av, sizeof(buf2));
		ft_strlcat(buf2, "/", sizeof(buf2));
		ft_strlcat(buf2, ls[i], sizeof(buf2));
		lstat(buf2, &(blocks));
		n_b += blocks.st_blocks;
	}
	return (n_b);
}

static char				*ft_av(char *av, t_env *env)
{
	char			buf[0xf00] = C_250;

	if (env->m[3] == 'x' || env->m[6] == 'x' || env->m[9] == 'x' ||
		env->m[9] == 't' || (env->m[9] == 'T' && env->m[6] == 'x') ||
		(env->m[9] == 'T' && env->m[3] == 'x'))
		ft_strlcpy(buf, C_124, sizeof(buf));
	if ((env->m[6] == 'S' && env->m[9] == 'x') || env->m[6] == 's' ||
		(env->m[6] == 'S' && env->m[9] == 't') ||
		(env->m[6] == 'S' && env->m[3] == 'x'))
		ft_strlcpy(buf, "\033[48;5;44;1;38;5;16m", sizeof(buf));
	if ((env->m[3] == 'S' && env->m[9] == 'x') || env->m[3] == 's' ||
		(env->m[6] == 'x' && (env->m[3] == 'S' || env->m[3] == 's')) ||
		(env->m[3] == 'S' && env->m[9] == 't') ||
		(env->m[3] == 'S' && env->m[6] == 's'))
		ft_strlcpy(buf, "\033[48;5;124;1;38;5;16m", sizeof(buf));
	if (env->m[0] == 'd' && ft_strlcpy(buf, C_18, sizeof(buf)))
	{
		if (env->m[8] == 'w' && (env->m[9] == '-' || env->m[9] == 'x'))
			ft_strlcpy(buf, "\033[48;5;220;1;38;5;16m", sizeof(buf));
		if (env->m[8] == 'w' && (env->m[9] == 't' || env->m[9] == 'T'))
			ft_strlcpy(buf, "\033[48;5;34;1;38;5;16m", sizeof(buf));
	}
	if (S_ISLNK(env->ls_lo.st_mode))
		ft_strlcpy(buf, C_127, sizeof(buf));
	return (ft_strjoin(buf, av));
}

static void				ft_print_arg(char *av, t_env *env)
{
	static char			buf[0xf000];
	int					i;

	if (S_ISLNK(env->ls_lo.st_mode) && env->op_active.l == true)
	{
		i = readlink(env->test_f, buf, 0xf000);
		buf[i] = '\0';
		if (env->op_active.g == false)
			ft_printf("%s -> ", av);
		else
			ft_printf("%s -> ", ft_av(av, env));
		ft_putendl(buf);
	}
	else
	{
		if (env->op_active.g == false)
			ft_printf("%s\n", av);
		else
			ft_printf("%s%s\n", ft_av(av, env), C_END);
	}
}

int						ft_print(char **ls, t_env *env)
{
	int					i;
	static int			count = 0;
	static char			buf2[0xF000];

	i = -1;
	if (env->op_active.l == true)
		ft_printf("%stotal %d%s\n", C_42, ft_nblocks(ls, env), C_END);
	while (ls[++i])
	{
		ft_strlcpy(buf2, env->av, sizeof(buf2));
		ft_strlcat(buf2, "/", sizeof(buf2));
		ft_strlcat(buf2, ls[i], sizeof(buf2));
		lstat(ft_strdup(buf2), &(env->ls_lo));
		stat(ft_strdup(buf2), &(env->ls_l));
		ft_m(env->ls_lo, env);
		if (env->op_active.l == true)
			if (ft_print_l(i, env) == -1)
				return (-1);
		ft_print_arg(ls[i], env);
	}
	++count;
	return (i);
}

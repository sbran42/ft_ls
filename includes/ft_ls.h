/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/01 13:00:59 by sbran             #+#    #+#             */
/*   Updated: 2014/10/03 18:07:08 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include "libft.h"

typedef struct		s_op
{
	bool			a;
	bool			rev;
	bool			rec;
	bool			l;
	bool			t;
	bool			g;
}					t_op;

typedef struct		s_env
{
	char			**ls;
	char			*args;
	char			*op;
	char			*av;
	char			*test_f;
	char			*ino;
	char			*ino_s;
	char			m[11];
	int				test;
	int				nb_op;
	int				nb_fold;
	int				nb_elem;
	int				max;
	int				max_elem;
	int				sub_s;
	int				minor;
	int				major;
	int				ac;
	struct stat		ls_l;
	struct stat		ls_k;
	struct stat		ls_lo;
	t_op			op_active;
	char			byte[7];
}					t_env;

/*
** ls -r
*/
void				ft_lr(t_env *env);
char				**ft_lt(char **ls, t_env *env);
char				**ft_lt_fold(char **ls, t_env *env);

void				ft_sort(int test, t_env *env);
char				**ft_sort_r(int test, char **ls);
char				**ft_init_r(char **arg, DIR *dir);
char				**ft_init_f(char *av, t_env *env);

int					ft_print(char **ls, t_env *env);
int					ft_print_l(t_env *env);
void				ft_m(struct stat stats, t_env *env);

void				ft_free_tab(char **arg);
char				**ft_reverse(char **arg, int test);

int					ft_rec(char *av, t_env *env, char **ls);
int					ft_la(char *av, t_env *env);
int					ft_ls(char *av, t_env *env);

#endif

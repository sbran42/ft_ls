/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:09:34 by sbran             #+#    #+#             */
/*   Updated: 2016/01/12 17:09:36 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct tm		ft_select_t(time_t time_a)
{
	struct tm			time_l;

	localtime_r(&time_a, &time_l);
	return (time_l);
}

void					ft_m(struct stat stats, t_env *env)
{
	env->m[0] = S_ISDIR(stats.st_mode) ? 'd' : '-';
	env->m[0] = S_ISLNK(stats.st_mode) ? 'l' : env->m[0];
	env->m[0] = S_ISCHR(stats.st_mode) ? 'c' : env->m[0];
	env->m[0] = S_ISBLK(stats.st_mode) ? 'b' : env->m[0];
	env->m[0] = S_ISFIFO(stats.st_mode) ? 'p' : env->m[0];
	env->m[0] = S_ISSOCK(stats.st_mode) ? 's' : env->m[0];
	env->m[1] = (stats.st_mode & S_IRUSR) ? 'r' : '-';
	env->m[2] = (stats.st_mode & S_IWUSR) ? 'w' : '-';
	env->m[3] = (stats.st_mode & S_IXUSR) ? 'x' : '-';
	env->m[4] = (stats.st_mode & S_IRGRP) ? 'r' : '-';
	env->m[5] = (stats.st_mode & S_IWGRP) ? 'w' : '-';
	env->m[6] = (stats.st_mode & S_IXGRP) ? 'x' : '-';
	env->m[7] = (stats.st_mode & S_IROTH) ? 'r' : '-';
	env->m[8] = (stats.st_mode & S_IWOTH) ? 'w' : '-';
	env->m[9] = (stats.st_mode & S_IXOTH) ? 'x' : '-';
	if (stats.st_mode & S_ISUID)
		env->m[3] = (env->m[3] == 'x') ? 's' : 'S';
	if (stats.st_mode & S_ISGID)
		env->m[6] = (env->m[6] == 'x') ? 's' : 'S';
	if (stats.st_mode & S_ISVTX)
		env->m[9] = (env->m[9] == 'x') ? 't' : 'T';
	env->minor = (S_ISCHR(stats.st_mode) || S_ISBLK(stats.st_mode)) ?
					minor(stats.st_rdev) : 0;
	env->major = (S_ISCHR(stats.st_mode) || S_ISBLK(stats.st_mode)) ?
					major(stats.st_rdev) : 0;
}

static void				ft_print_link(struct stat stats, int i, t_env *env)
{
	// struct tm			time_a;
	// struct group		*grp;
	// struct passwd	*usr;
	// char				ugid[2][0xf000];
	// char				mtime[80];

	++i;
	// ft_printf("%d => ", env->max);
	// 	ft_printf("%d\n", stats.st_gid);

	env->max += 0;
	getgrgid(stats.st_uid);

	// ft_printf("%d => ", stats.st_uid);
	// 	ft_printf("%d\n", stats.st_gid);
	// if ((usr = getpwuid(stats.st_uid)) == NULL)
	// 	ft_strlcpy(ugid[0], ft_itoa(stats.st_uid), sizeof(ugid[0]));
	// else	
	// 	ft_strlcpy(ugid[0], usr->pw_name, sizeof(ugid[0]));
	// if ((grp = getgrgid(stats.st_gid)) == NULL)
	// 	ft_strlcpy(ugid[1], ft_itoa(stats.st_gid), sizeof(ugid[1]));
	// else
	// 	ft_strlcpy(ugid[1], grp->gr_name, sizeof(ugid[1]));
	// i = ((usr = getpwuid(stats.st_uid)) == NULL) ?
	// ft_strlcpy(ugid[0], ft_itoa(stats.st_uid), sizeof(ugid[0])) :
	// time_a = S_ISLNK(stats.st_mode) ? ft_select_t(stats.st_mtime) :
	// 										ft_select_t(stats.st_mtime);
	// strftime(mtime, sizeof(mtime), "%b %d %T", &time_a);
	// if (S_ISCHR(stats.st_mode) || S_ISBLK(stats.st_mode))
	// 	ft_printf("%s%s %d\t%s\t%s\t%d, %d\t%s%s ", C_39, env->m,
	// 	stats.st_nlink, "moi", "ugid[1]", env->major, env->minor,
	// 	ft_strsub(mtime, 0, 12), C_END);
	// else
	// 	ft_printf("%s%s %d\t%s\t%s\t%u\t%s%s ", C_39, env->m,
	// 	stats.st_nlink, "ugid[0]", "ugid[1]", stats.st_size,
	// 	ft_strsub(mtime, 0, 12), C_END);
}

int						ft_print_l(int i, t_env *env)
{
	if (S_ISLNK(env->ls_lo.st_mode))
		ft_print_link(env->ls_lo, i, env);
	else
		ft_print_link(env->ls_l, i, env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:58:49 by gfernand          #+#    #+#             */
/*   Updated: 2019/09/03 13:18:14 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		perms(mode_t st)
{
	char perms[11];
	if (st && S_ISREG(st))
		perms[0] = "-";
	else if (st && s_ISDIR(st))
		perms[0] = "d";
	else if (st && S_ISFIFO(st))
		perms[0] = "|";
	else if (st && S_ISSOCK(st))
		perms[0] = "s";
	else if (st && S_ISCHR(st))
		perms[0] = "c";
	else if (st && S_ISBLK(st))
		perms[0] = "b";
	else
		perms[0] = "l";
	perms[1] = (st && S_IRUSR) ? "r" : "-";
	perms[2] = (st && S_IWUSR) ? "w" : "-";
	perms[3] = (st && S_IXUSR) ? "x" : "-";
	perms[4] = (st && S_IRGRP) ? "r" : "-";
	perms[5] = (st && S_IWGRP) ? "w" : "-";
	perms[6] = (st && S_IXGRP) ? "x" : "-";
	perms[7] = (st && S_IROTH) ? "r" : "-";
	perms[8] = (st && S_IWOTH) ? "w" : "-";
	perms[9] = (st && S_IXOTH) ? "x" : "-";
	perms[10] = "\0";
	ft_putstr(perms);
}

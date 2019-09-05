/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:22:24 by gfernand          #+#    #+#             */
/*   Updated: 2019/09/03 14:15:55 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_a(char *filepath)
{
	struct dirent	*de;
	DIR				*dir;

	if(!(dir = opendir(filepath)))
		return (NULL);
	while((de = readdir(dir)) != NULL)
		ft_putendl(de->d_name);
}

void		ls_bigr(char *filepath)
{
	char			*newpath;
	struct dirent	*de;
	DIR				*dir;

	if(!(dir = opendir(filepath)))
		return (NULL);
	while((de = readdir(dir)) != NULL)
	{
		if(ft_strcmp(de->d_name, ".") != 0 && ft_strcmp(de->d_name, "..") != 0)
		{
			ft_putendl(de->d_name);
			ft_strcpy(newpath, filepath);
			ft_strcat(newpath, "/");
			ft_strcat(newpath, de->d_name);
			ls_rec(newpath);
		}
	}
	closedir(dir);
}

int			main(int ac, char **av)
{
	DIR	*dir;

	dir = opendir(".");

}



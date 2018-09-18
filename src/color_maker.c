/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:38:10 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/13 12:38:12 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_colors(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->map->lin)
	{
		j = -1;
		while (++j < info->map->col)
			if (info->a[i][j].color != 16777215)
				return (1);
	}
	return (0);
}

void	change_colors(t_info *info, int flag)
{
	int		i;
	int		j;

	if (flag)
	{
		i = -1;
		while (++i < info->map->lin)
		{
			j = -1;
			while (++j < info->map->col)
			{
				if (info->a[i][j].z == 0)
					info->a[i][j].color = 255;
			}
		}
	}
}

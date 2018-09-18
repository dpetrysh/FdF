/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:36:17 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/02/24 01:36:19 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zsuv_x(t_info *info, int flag)
{
	int i;
	int j;

	i = -1;
	while (++i < info->map->lin)
	{
		j = -1;
		while (++j < info->map->col)
		{
			if (flag == 1)
				info->a[i][j].x += 10;
			else
				info->a[i][j].x -= 10;
		}
	}
	mlx_clear_window(info->env.mlx, info->env.win);
}

void	zsuv_y(t_info *info, int flag)
{
	int i;
	int j;

	i = -1;
	while (++i < info->map->lin)
	{
		j = -1;
		while (++j < info->map->col)
		{
			if (flag == 1)
				info->a[i][j].y += 10;
			else
				info->a[i][j].y -= 10;
		}
	}
	mlx_clear_window(info->env.mlx, info->env.win);
}

void	zsuv(int key, t_info *info)
{
	if (key == 124)
		zsuv_x(info, 1);
	if (key == 123)
		zsuv_x(info, 0);
	if (key == 125)
		zsuv_y(info, 1);
	if (key == 126)
		zsuv_y(info, 0);
}

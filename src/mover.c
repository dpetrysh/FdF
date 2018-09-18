/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:27:36 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/02/19 13:27:38 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_center_mon(t_info *info)
{
	int i;
	int j;
	int l;
	int h;

	l = WIN_LEN - info->a[0][info->map->col - 1].x;
	h = WIN_HEI - info->a[info->map->lin - 1][0].y;
	i = -1;
	while (++i < info->map->lin)
	{
		j = -1;
		while (++j < info->map->col)
		{
			info->a[i][j].x = info->a[i][j].x + l / 2;
			info->a[i][j].y = info->a[i][j].y + h / 2;
		}
	}
	draw_figure(info->a, info->map, &info->env);
}

void	move_center(t_point **a, t_map *map, int flag)
{
	int				i;
	int				j;
	static t_dx_dy	dd;

	if (flag)
		center_coord(a, map, &dd);
	i = -1;
	while (++i < map->lin)
	{
		j = -1;
		while (++j < map->col)
		{
			if (flag == 1)
			{
				a[i][j].x = a[i][j].x - dd.dx;
				a[i][j].y = a[i][j].y - dd.dy;
			}
			else
			{
				a[i][j].x = a[i][j].x + dd.dx;
				a[i][j].y = a[i][j].y + dd.dy;
			}
		}
	}
}

void	center_coord(t_point **a, t_map *map, t_dx_dy *dd)
{
	dd->dx = x_slide(a, map);
	dd->dy = y_slide(a, map);
}

double	x_slide(t_point **a, t_map *map)
{
	int x_min;
	int x_max;

	x_min = a[0][0].x;
	x_min = (x_min < a[0][map->col - 1].x ? x_min : a[0][map->col - 1].x);
	x_min = (x_min < a[map->lin - 1][0].x ? x_min : a[map->lin - 1][0].x);
	x_min = (x_min < a[map->lin - 1][map->col - 1].x ? x_min :
		a[map->lin - 1][map->col - 1].x);
	x_max = a[0][0].x;
	x_max = (x_max > a[0][map->col - 1].x ? x_max : a[0][map->col - 1].x);
	x_max = (x_max > a[map->lin - 1][0].x ? x_max : a[map->lin - 1][0].x);
	x_max = (x_max > a[map->lin - 1][map->col - 1].x ? x_max :
		a[map->lin - 1][map->col - 1].x);
	return ((x_min + x_max) / 2);
}

double	y_slide(t_point **a, t_map *map)
{
	int y_min;
	int y_max;

	y_min = a[0][0].y;
	y_min = (y_min < a[0][map->col - 1].y ? y_min : a[0][map->col - 1].y);
	y_min = (y_min < a[map->lin - 1][0].y ? y_min : a[map->lin - 1][0].y);
	y_min = (y_min < a[map->lin - 1][map->col - 1].y ? y_min :
		a[map->lin - 1][map->col - 1].y);
	y_max = a[0][0].y;
	y_max = (y_max > a[0][map->col - 1].y ? y_max : a[0][map->col - 1].y);
	y_max = (y_max > a[map->lin - 1][0].y ? y_max : a[map->lin - 1][0].y);
	y_max = (y_max > a[map->lin - 1][map->col - 1].y ? y_max :
		a[map->lin - 1][map->col - 1].y);
	return ((y_min + y_max) / 2);
}

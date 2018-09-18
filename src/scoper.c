/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:34:27 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/01/29 17:34:28 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_scope(int key, t_info *info)
{
	if (key == 69)
		scope_plus(info);
	if (key == 78)
		scope_minus(info);
}

void	scope_plus(t_info *info)
{
	int i;
	int j;

	i = -1;
	move_center(info->a, info->map, 1);
	while (++i < info->map->lin)
	{
		j = -1;
		while (++j < info->map->col)
		{
			info->a[i][j].x = info->a[i][j].x * 1.1;
			info->a[i][j].y = info->a[i][j].y * 1.1;
			info->a[i][j].z = info->a[i][j].z * 1.1;
		}
	}
	move_center(info->a, info->map, 0);
	mlx_clear_window(info->env.mlx, info->env.win);
}

void	scope_minus(t_info *info)
{
	int i;
	int j;

	move_center(info->a, info->map, 1);
	i = -1;
	while (++i < info->map->lin)
	{
		j = -1;
		while (++j < info->map->col)
		{
			info->a[i][j].x = info->a[i][j].x / 1.1;
			info->a[i][j].y = info->a[i][j].y / 1.1;
			info->a[i][j].z = info->a[i][j].z / 1.1;
		}
	}
	move_center(info->a, info->map, 0);
	mlx_clear_window(info->env.mlx, info->env.win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:27:57 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/02/19 13:27:58 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	turn_back(int key, t_info *info)
{
	if (key == 0)
		turn_back_z(info);
	if (key == 1)
		turn_back_x(info);
	if (key == 32)
		turn_back_y(info);
}

void	turn_back_z(t_info *info)
{
	double	x;
	double	y;
	int		i;
	int		j;

	move_center(info->a, info->map, 1);
	i = -1;
	while (++i < info->map->lin)
	{
		j = -1;
		while (++j < info->map->col)
		{
			x = info->a[i][j].x;
			y = info->a[i][j].y;
			info->a[i][j].x = x * cos(M_PI / 90) + y * sin(M_PI / 90);
			info->a[i][j].y = -x * sin(M_PI / 90) + y * cos(M_PI / 90);
		}
	}
	move_center(info->a, info->map, 0);
	mlx_clear_window(info->env.mlx, info->env.win);
}

void	turn_back_x(t_info *info)
{
	double	z;
	double	y;
	int		i;
	int		j;

	move_center(info->a, info->map, 1);
	i = -1;
	while (++i < info->map->lin)
	{
		j = -1;
		while (++j < info->map->col)
		{
			z = info->a[i][j].z;
			y = info->a[i][j].y;
			info->a[i][j].y = y * cos(M_PI / 90) + z * sin(M_PI / 90);
			info->a[i][j].z = -y * sin(M_PI / 90) + z * cos(M_PI / 90);
		}
	}
	move_center(info->a, info->map, 0);
	mlx_clear_window(info->env.mlx, info->env.win);
}

void	turn_back_y(t_info *info)
{
	double	z;
	double	x;
	int		i;
	int		j;

	move_center(info->a, info->map, 1);
	i = -1;
	while (++i < info->map->lin)
	{
		j = -1;
		while (++j < info->map->col)
		{
			x = info->a[i][j].x;
			z = info->a[i][j].z;
			info->a[i][j].x = x * cos(M_PI / 90) - z * sin(M_PI / 90);
			info->a[i][j].z = x * sin(M_PI / 90) + z * cos(M_PI / 90);
		}
	}
	move_center(info->a, info->map, 0);
	mlx_clear_window(info->env.mlx, info->env.win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:17:11 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/01/16 20:17:16 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_figure(t_point **a, t_map *map, t_env *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->lin)
	{
		j = -1;
		while (++j < map->col - 1)
			line_print(a[i][j], a[i][j + 1], e);
	}
	j = -1;
	while (++j < map->col)
	{
		i = -1;
		while (++i < map->lin - 1)
			line_print(a[i][j], a[i + 1][j], e);
	}
}

void	line_low(t_point p1, t_point p2, t_env *e, t_dx_dy *dx_dy)
{
	int		d;
	int		x;
	int		y;
	int		yi;
	t_point	x_y;

	yi = (dx_dy->dy < 0 ? -1 : 1);
	dx_dy->dy = (dx_dy->dy < 0 ? -dx_dy->dy : dx_dy->dy);
	d = 2 * dx_dy->dy - dx_dy->dx;
	x = p1.x - 1;
	y = p1.y;
	while (++x <= p2.x)
	{
		x_y.x = x;
		x_y.y = y;
		color_pixel(p1, p2, e, x_y);
		if (d > 0)
		{
			y += yi;
			d -= 2 * dx_dy->dx;
		}
		d += 2 * dx_dy->dy;
	}
}

void	line_high(t_point p1, t_point p2, t_env *e, t_dx_dy *dx_dy)
{
	int		d;
	int		x;
	int		y;
	int		xi;
	t_point	x_y;

	xi = (dx_dy->dx < 0 ? -1 : 1);
	dx_dy->dx = (dx_dy->dx < 0 ? -dx_dy->dx : dx_dy->dx);
	d = 2 * dx_dy->dx - dx_dy->dy;
	x = p1.x;
	y = p1.y - 1;
	while (++y <= p2.y)
	{
		x_y.x = x;
		x_y.y = y;
		color_pixel(p1, p2, e, x_y);
		if (d > 0)
		{
			x += xi;
			d -= 2 * dx_dy->dy;
		}
		d += 2 * dx_dy->dx;
	}
}

void	color_pixel(t_point p1, t_point p2, t_env *e, t_point p)
{
	double	l1;
	double	l2;

	p.color = p1.color;
	if (p1.color - p2.color != 0)
	{
		p.color = 0;
		l2 = sqrt(pow((p.x - p1.x), 2) + pow((p.y - p1.y), 2)) /
		sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
		l1 = sqrt(pow((p.x - p2.x), 2) + pow((p.y - p2.y), 2)) /
		sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
		p.color = get_rgb(p1, p2, l1, l2);
	}
	mlx_pixel_put(e->mlx, e->win, p.x, p.y, p.color);
}

void	line_print(t_point p1, t_point p2, t_env *e)
{
	t_dx_dy	dx_dy1;
	t_dx_dy	dx_dy2;

	dx_dy1.dx = p2.x - p1.x;
	dx_dy1.dy = p2.y - p1.y;
	dx_dy2.dx = p1.x - p2.x;
	dx_dy2.dy = p1.y - p2.y;
	if (ABS((p2.y - p1.y)) < ABS((p2.x - p1.x)))
	{
		if (p1.x > p2.x)
			line_low(p2, p1, e, &dx_dy2);
		else
			line_low(p1, p2, e, &dx_dy1);
	}
	else
	{
		if (p1.y > p2.y)
			line_high(p2, p1, e, &dx_dy2);
		else
			line_high(p1, p2, e, &dx_dy1);
	}
}

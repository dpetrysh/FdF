/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 00:53:55 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/02/24 00:53:57 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_hook(int key, t_info *info)
{
	if (key == 53)
		exit(0);
	if (key == 124 || key == 123 || key == 125 || key == 126)
		zsuv(key, info);
	if (key == 35)
		info->p = !info->p;
	if (key == 6 || key == 7 || key == 16)
		turn_axis(key, info);
	if (key == 0 || key == 1 || key == 32)
		turn_back(key, info);
	if (key == 69 || key == 78)
		make_scope(key, info);
	if (key == 8)
		change_colors(info, !check_colors(info));
	mlx_clear_window(info->env.mlx, info->env.win);
	draw_figure(info->a, info->map, &info->env);
	return (0);
}

long long	get_rgb(t_point p1, t_point p2, double l1, double l2)
{
	long long color;

	color = 0;
	if ((long long)((p1.color % 256) * l1 + (p2.color % 256) * l2) < 256)
		color += (long long)((p1.color % 256) * l1 + (p2.color % 256) * l2);
	else
		color += 255;
	if ((long long)(((p1.color / 256) % 256) * l1 +
		((p2.color / 256) % 256) * l2) * 256 < 65281)
		color += (long long)(((p1.color / 256) % 256) * l1 +
			((p2.color / 256) % 256) * l2) * 256;
	else
		color += 65280;
	if ((long long)(((p1.color / 65536) % 256) * l1 +
		((p2.color / 65536) % 256) * l2) * 65536 < 16711681)
		color += (long long)(((p1.color / 65536) % 256) * l1 +
			((p2.color / 65536) % 256) * l2) * 65536;
	else
		color += 16711680;
	return (color);
}

int			main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (argc_error(argc));
	info.p = 0;
	info.env.mlx = mlx_init();
	info.env.win = mlx_new_window(info.env.mlx, WIN_LEN, WIN_HEI, "mlx42");
	if (!(info.map = get_map(argv[1])))
		return (map_error());
	if (!(info.a = create_array(info.map, argv[1])))
		return (map_error());
	move_center_mon(&info);
	mlx_hook(info.env.win, 2, 5, key_hook, &info);
	mlx_hook(info.env.win, 17, 1L << 17, exit_x, &info);
	mlx_loop(info.env.mlx);
	return (0);
}

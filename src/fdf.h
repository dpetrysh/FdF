/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:17:21 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/01/16 20:17:22 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

# define WIN_LEN 1000
# define WIN_HEI 1000
# define ABS(x)	((x) < 0 ? -(x) : (x))

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	long long	color;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_map
{
	int			col;
	int			lin;
	double		z_max;
}				t_map;

typedef struct	s_info
{
	int			p;
	t_env		env;
	t_map		*map;
	t_point		**a;
	t_point		**b;
}				t_info;

typedef struct	s_dx_dy
{
	double		dx;
	double		dy;
	double		dz;
}				t_dx_dy;

void			p_projection(t_info *info);
long long		get_rgb(t_point p1, t_point p2, double l1, double l2);

void			move_center_mon(t_info *info);
void			move_center(t_point **a, t_map *map, int flag);
double			x_slide(t_point **a, t_map *map);
double			y_slide(t_point **a, t_map *map);
void			center_coord(t_point **a, t_map *map, t_dx_dy *dd);

void			draw_figure(t_point **a, t_map *map, t_env *e);
void			line_low(t_point p1, t_point p2, t_env *e, t_dx_dy *dx_dy);
void			line_high(t_point p1, t_point p2, t_env *e, t_dx_dy *dx_dy);
void			color_pixel(t_point p1, t_point p2, t_env *e, t_point p);
void			line_print(t_point p1, t_point p2, t_env *e);

t_point			**create_array(t_map *map, char *file);
t_point			*get_points(char **ar, t_map *map, int line_num);
int				count_cols(char **ar, t_map *map);
int				get_color(char *str);
t_map			*get_map(char *file);

void			make_scope(int key, t_info *info);
void			scope_plus(t_info *info);
void			scope_minus(t_info *info);

void			zsuv_x(t_info *info, int flag);
void			zsuv_y(t_info *info, int flag);
void			zsuv(int key, t_info *info);

void			turn_axis(int key, t_info *info);
void			turn_z(t_info *info);
void			turn_x(t_info *info);
void			turn_y(t_info *info);

int				exit_x(void);
int				argc_error(int argc);
int				map_error(void);

void			clean(char **ar, char *line);
void			clean_array(char **ar);
int				check_el(char *str);
int				check_alpha(char *str);

void			turn_back(int key, t_info *info);
void			turn_back_z(t_info *info);
void			turn_back_x(t_info *info);
void			turn_back_y(t_info *info);

int				check_colors(t_info *info);
void			change_colors(t_info *info, int flag);

#endif

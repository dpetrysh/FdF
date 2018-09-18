/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:50:49 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/01/25 13:50:50 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*get_map(char *file)
{
	int		fd;
	int		i;
	t_map	*map;
	char	*line;
	char	**ar;

	map = (t_map *)malloc(sizeof(t_map));
	if ((fd = open(file, O_RDONLY)) == -1 || get_next_line(fd, &line) == -1)
		return (NULL);
	map->z_max = 0;
	ar = ft_strsplit(line, ' ');
	map->col = count_cols(ar, map);
	clean(ar, line);
	i = 0;
	while (get_next_line(fd, &line) && ++i)
	{
		ar = ft_strsplit(line, ' ');
		if (map->col != count_cols(ar, map))
			return (NULL);
		clean(ar, line);
	}
	map->lin = i + 1;
	close(fd);
	return (map);
}

int		get_color(char *str)
{
	int			i;
	int			len;
	long long	color;
	char		ch_col;

	color = 0;
	if (ft_strstr(str, ",0x"))
	{
		len = ft_strlen(ft_strstr(str, ",0x") + 3);
		str = ft_strstr(str, ",0x");
		i = 3;
		while ((ch_col = str[i]))
		{
			if (ch_col >= 65 && ch_col <= 70)
				color += (ch_col - 55) * pow(16, --len);
			else if (ch_col >= 97 && ch_col <= 102)
				color += (ch_col - 87) * pow(16, --len);
			else if (ft_isdigit(ch_col))
				color += (ch_col - '0') * pow(16, --len);
			else
				return (-1);
			i++;
		}
	}
	return (color);
}

int		count_cols(char **ar, t_map *map)
{
	int		i;

	i = 0;
	while (ar && ar[i])
		i++;
	if (map)
	{
		while (*ar)
		{
			map->z_max = (map->z_max > ABS((ft_atoi(*ar))) ?
				map->z_max : ABS((ft_atoi(*ar))));
			ar++;
		}
	}
	if (!map->z_max)
		map->z_max = 1;
	return (i);
}

t_point	*get_points(char **ar, t_map *map, int line_num)
{
	int		i;
	double	l_size;
	t_point	*points;

	i = 0;
	if (map->col > 1)
		l_size = 500 / (map->col - 1);
	else
		l_size = 500;
	points = (t_point *)malloc(sizeof(t_point) * map->col);
	while (ar[i])
	{
		if (!check_el(ar[i]))
			return (NULL);
		points[i].x = i * l_size;
		points[i].y = line_num * l_size;
		points[i].z = ft_atoi(ar[i]) * (180 / (map->z_max));
		points[i].color = 16777215;
		if (get_color(ar[i]))
			points[i].color = get_color(ar[i]);
		free(ar[i]);
		i++;
	}
	free(ar);
	return (points);
}

t_point	**create_array(t_map *map, char *file)
{
	int		fd;
	int		i;
	char	*line;
	t_point	**a;

	fd = open(file, O_RDONLY);
	i = -1;
	a = (t_point **)malloc(sizeof(t_point *) * map->lin);
	while (++i < map->lin && get_next_line(fd, &line))
	{
		if (!(a[i] = get_points(ft_strsplit(line, ' '), map, i)))
		{
			free(a[i]);
			free(line);
			return (NULL);
		}
		free(line);
	}
	close(fd);
	return (a);
}

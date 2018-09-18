/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:24:29 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/02/27 19:24:30 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_x(void)
{
	exit(1);
}

int		argc_error(int argc)
{
	if (argc < 2)
		perror("Arguments missing");
	else
		perror("Too many arguments");
	return (-1);
}

int		map_error(void)
{
	perror("Error");
	write(2, "Your map isn't correct\n", 23);
	return (-1);
}

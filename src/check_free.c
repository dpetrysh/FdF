/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:17:43 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/07 14:17:44 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean(char **ar, char *line)
{
	clean_array(ar);
	free(line);
}

void	clean_array(char **ar)
{
	int i;

	i = 0;
	while (ar && ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

int		check_el(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != 44 &&
			str[i] != 45 && str[i] != 43)
			return (0);
	if (ft_strchr(str, ',') && !ft_strstr(str, ",0x"))
		return (0);
	if (ft_strstr(str, ",0x") && (ft_strlen(ft_strstr(str, ",0x") + 3) > 8 ||
		!check_alpha(ft_strstr(str, ",0x") + 3)))
	{
		write(2, "Incorrect color format\n", 23);
		return (0);
	}
	return (1);
}

int		check_alpha(char *str)
{
	while (*str)
	{
		if ((*str > 70 && *str < 91) || (*str > 102 && *str < 122))
			return (0);
		str++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:34:23 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/14 12:34:24 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordlen(char const *s, char c)
{
	int i;

	i = 0;
	while (*s == c)
		s++;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}
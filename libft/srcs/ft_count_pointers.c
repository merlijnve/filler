/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_pointers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 11:28:39 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/31 11:29:40 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_pointers(char **p)
{
	int c;

	c = 0;
	while (p[c] != NULL)
		c++;
	return (c);
}

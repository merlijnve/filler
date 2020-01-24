/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 12:57:26 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/30 14:00:36 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mapdel(void **map)
{
	int b;

	b = 0;
	while (map[b])
	{
		free(map[b]);
		b++;
	}
	free(map);
	return (0);
}

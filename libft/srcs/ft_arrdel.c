/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 16:15:32 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/12/13 20:21:25 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel(char **as)
{
	int i;

	i = 0;
	while (as[i] != NULL)
	{
		ft_memdel((void **)&as[i]);
		i++;
	}
	free(as);
}

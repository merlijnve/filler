/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 20:31:39 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/01/14 13:39:07 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int x;
	int y;

	x = ft_isdigit(c);
	y = ft_isalpha(c);
	if (x == 1 || y == 1)
		return (1);
	else
		return (0);
}

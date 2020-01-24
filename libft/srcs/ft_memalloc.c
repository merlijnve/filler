/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 16:59:35 by jboer          #+#    #+#                */
/*   Updated: 2019/09/11 15:44:34 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *a;

	a = malloc(size);
	if (a == NULL)
		return (NULL);
	ft_memset(a, 0, size);
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_llintlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 19:41:11 by jboer          #+#    #+#                */
/*   Updated: 2019/09/27 14:31:22 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_llintlen(long long int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < -9223372036854775807)
		return (20);
	if (n < 0)
	{
		len++;
		n = n * (long long)-1;
	}
	while (n >= (long long)1)
	{
		n = n / (long long)10;
		len++;
	}
	return (len);
}

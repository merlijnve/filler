/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_straddtoend.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 18:06:31 by jboer          #+#    #+#                */
/*   Updated: 2019/09/18 18:17:05 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_straddtoend(char *str, char *add)
{
	char	*buf;
	size_t	l;

	l = ft_strlen(str);
	buf = ft_strnew(ft_strlen(str) + l);
	if (buf == NULL)
		return (NULL);
	ft_strcpy(buf, str);
	ft_strcpy(&buf[l], add);
	ft_strdel(&str);
	return (buf);
}

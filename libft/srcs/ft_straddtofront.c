/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_straddtofront.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 15:42:28 by jboer          #+#    #+#                */
/*   Updated: 2019/09/18 19:48:31 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_straddtofront(char *str, char *add)
{
	char	*buf;
	size_t	addl;

	addl = ft_strlen(add);
	buf = ft_strnew(ft_strlen(str) + addl);
	if (buf == NULL)
		return (NULL);
	ft_strcpy(&buf[addl], str);
	ft_strncpy(buf, add, addl);
	ft_strdel(&str);
	return (buf);
}

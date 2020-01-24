/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 16:08:05 by mvan-eng       #+#    #+#                */
/*   Updated: 2020/01/16 17:56:54 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/srcs/libft.h"
#include <fcntl.h>

void	print_coordinate(int h, int v)
{
	ft_putnbr(v);
	ft_putchar(' ');
	ft_putnbr(h);
	ft_putchar('\n');
}

int		main(void)
{
	t_fil	*fil;
	char	*line;

	fil = (t_fil *)malloc(sizeof(t_fil));
	fil->field = NULL;
	fil->tok = NULL;
	fil->turn = 0;
	get_game_info(fil);
	while (get_next_line(0, &line))
	{
		ft_strdel(&line);
		get_field(fil);
		get_token(fil);
		parse_token(fil);
		calc_possibilities(fil);
		print_coordinate(fil->pos.hor, fil->pos.ver);
		fil->turn++;
	}
}

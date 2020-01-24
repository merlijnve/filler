/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 16:01:24 by mvan-eng       #+#    #+#                */
/*   Updated: 2020/01/16 19:58:06 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/srcs/libft.h"

# define OK 0
# define ERROR -1

/*
**	Token struct
**	tv			token vertical
**	th			token horizontal
**	psh			piece start horizontal
**	peh			piece end horizontal
**	psv			piece start vertical
**	pev			piece end vertical
**	tok			token array
*/

typedef struct	s_tok
{
	int			tv;
	int			th;
	int			psh;
	int			peh;
	int			psv;
	int			pev;
	char		**tok;
}				t_tok;

/*
**	Coordinate struct
*/

typedef struct	s_cor
{
	int			hor;
	int			ver;
	int			distance;
}				t_cor;

/*
**	MAIN STRUCT
**	p			player character (in uppercase)
** 	o			opponent character (in uppercase)
**	fhor		field horizontal size
**	fver		field vertical size
**	field		field 2d array
**	turn		turn counter
**	dir			1 means go down, 2 means go up
**	psp			player start point coordinate
**	osp			opponent start point coordinate
**	tok			token array
**	pos			best possibility
*/

typedef struct	s_fil
{
	char		p;
	char		o;
	int			fhor;
	int			fver;
	char		**field;
	int			turn;
	int			dir;
	t_cor		psp;
	t_cor		osp;
	t_tok		*tok;
	t_cor		pos;
}				t_fil;

void			get_game_info(t_fil *fil);
void			get_field(t_fil *fil);
void			get_token(t_fil *fil);
void			parse_token(t_fil *fil);
void			calc_possibilities(t_fil *fil);

#endif

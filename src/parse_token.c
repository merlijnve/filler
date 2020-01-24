/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 13:37:07 by mvan-eng       #+#    #+#                */
/*   Updated: 2020/01/10 16:13:44 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	FIND_STARTPOSITIONS
**	sets startposition coordinates in t_fil struct
*/

static void			find_startpositions(t_fil *fil)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (fil->field[i] != NULL)
	{
		while (fil->field[i][j] != '\0')
		{
			if (fil->field[i][j] == fil->p)
			{
				fil->psp.hor = j;
				fil->psp.ver = i;
			}
			if (fil->field[i][j] == fil->o)
			{
				fil->osp.hor = j;
				fil->osp.ver = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	fil->dir = fil->psp.ver > fil->osp.ver ? 2 : 1;
}

/*
**	FIND_PV
**	finds piece vertical size using top asterisk and bottom asterisk
*/

static void			find_pv(t_fil *fil)
{
	char	**token;
	int		i;
	int		j;
	int		last;

	j = 0;
	i = 0;
	last = -1;
	token = fil->tok->tok;
	while (token[i] != NULL)
	{
		while (token[i][j] != '\0')
		{
			if (token[i][j] == '*')
			{
				if (last == -1)
					fil->tok->psv = i;
				last = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
	fil->tok->pev = last;
}

/*
**	FIND_PH
**	finds piece horizontal size using top asterisk and bottom asterisk
*/

static void			find_ph(t_fil *fil)
{
	char	**token;
	int		i;
	int		j;
	int		last;

	j = 0;
	i = 0;
	last = -1;
	token = fil->tok->tok;
	while (token[i][j] != '\0')
	{
		while (token[i] != NULL)
		{
			if (token[i][j] == '*')
			{
				if (last == -1)
					fil->tok->psh = j;
				last = j;
			}
			i++;
		}
		j++;
		i = 0;
	}
	fil->tok->peh = last;
}

/*
**	PARSE_TOKEN
**	starts parsing info about piece width and height
*/

void				parse_token(t_fil *fil)
{
	if (fil->turn == 0)
		find_startpositions(fil);
	find_ph(fil);
	find_pv(fil);
}

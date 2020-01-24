/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_possibilities.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 20:28:54 by mvan-eng       #+#    #+#                */
/*   Updated: 2020/01/16 19:57:42 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_cor	find_token_mid(t_fil *fil, t_cor f)
{
	t_cor mid;

	if (fil->dir == 1)
	{
		mid.hor = fil->tok->peh + f.hor;
		mid.ver = fil->tok->pev + f.ver;
	}
	else
	{
		mid.hor = fil->tok->psh + f.hor;
		mid.ver = fil->tok->pev + f.ver;
	}
	return (mid);
}

static int		uncomplete_pythagoras(t_cor a, t_cor b)
{
	int		dx;
	int		dy;

	dx = b.hor - a.hor;
	dy = b.ver - a.ver;
	return (dx * dx + dy * dy);
}

static int		calc_opp_distance(t_fil *fil, t_cor f)
{
	t_cor	olast;
	t_cor	mid;
	int		distance;

	olast.hor = 0;
	olast.ver = 0;
	mid = find_token_mid(fil, f);
	distance = 100000;
	while (olast.ver < fil->fver)
	{
		while (olast.hor < fil->fhor)
		{
			if ((fil->field[olast.ver][olast.hor] == fil->o ||
			fil->field[olast.ver][olast.hor] == fil->o + 32) &&
			distance > uncomplete_pythagoras(olast, mid))
				distance = uncomplete_pythagoras(olast, mid);
			olast.hor++;
		}
		olast.hor = 0;
		olast.ver++;
	}
	return (distance);
}

static int		check_overlap(t_fil *fil, t_cor f)
{
	t_cor	d;
	int		overlap;

	overlap = 0;
	d.hor = fil->tok->psh;
	d.ver = fil->tok->psv;
	while (d.ver <= fil->tok->pev)
	{
		while (d.hor <= fil->tok->peh)
		{
			if (fil->field[f.ver + d.ver][f.hor + d.hor] != '.'
			&& fil->tok->tok[d.ver][d.hor] != '.')
			{
				if (fil->field[f.ver + d.ver][f.hor + d.hor] == fil->o
				|| fil->field[f.ver + d.ver][f.hor + d.hor] == fil->o + 32)
					return (ERROR);
				overlap++;
			}
			d.hor++;
		}
		d.ver++;
		d.hor = fil->tok->psh;
	}
	return (overlap);
}

void			calc_possibilities(t_fil *fil)
{
	t_cor	f;
	int		tempd;

	tempd = 10000;
	f.ver = -1 * fil->tok->psv;
	f.hor = -1 * fil->tok->psh;
	while (f.ver < fil->fver - fil->tok->pev)
	{
		while (f.hor < fil->fhor - fil->tok->peh)
		{
			if (check_overlap(fil, f) == 1 && calc_opp_distance(fil, f) < tempd)
			{
				tempd = calc_opp_distance(fil, f);
				fil->pos.hor = f.hor;
				fil->pos.ver = f.ver;
			}
			f.hor++;
		}
		f.hor = -1 * fil->tok->psh;
		f.ver++;
	}
}

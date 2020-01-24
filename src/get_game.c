/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 23:00:30 by mvan-eng       #+#    #+#                */
/*   Updated: 2020/01/16 16:06:50 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		allocate_token(t_fil *fil)
{
	char	*line;
	char	**split;
	int		ret;

	fil->tok = (t_tok *)malloc(sizeof(t_tok));
	if (fil->tok == NULL)
		exit(ERROR);
	ret = get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	fil->tok->tv = ft_atoi(split[1]);
	fil->tok->th = ft_atoi(split[2]);
	free(line);
	ft_arrdel(split);
}

/*
**	ALLOCATE_FIELD
**	allocates a char** the size of field horizontal and
**	field vertical dimensions
*/

static void		allocate_field(t_fil *fil)
{
	int	i;

	i = 0;
	fil->field = (char **)malloc(sizeof(char *) * fil->fver + 1);
	if (fil->field == NULL)
		exit(ERROR);
	fil->field[fil->fver] = NULL;
	while (i < fil->fver)
	{
		fil->field[i] = ft_strnew((size_t)fil->fhor);
		if (fil->field[i] == NULL)
			exit(ERROR);
		i++;
	}
}

/*
**	GET_FIELD
**	copies current field to fil->field
*/

void			get_field(t_fil *fil)
{
	char	*line;
	int		i;

	i = 0;
	if (fil->field == NULL)
		allocate_field(fil);
	while (get_next_line(0, &line) && ft_strstr(line, "000") == NULL)
		ft_strdel(&line);
	while (i < fil->fver)
	{
		ft_strcpy(fil->field[i], &line[4]);
		i++;
		if (i < fil->fver)
		{
			ft_strdel(&line);
			get_next_line(0, &line);
		}
	}
	ft_strdel(&line);
}

/*
**	GET_TOKEN
**	gets token width / token height
**	copies token to fil->tok->tok
** 	(does not parse the trimmed piece)
*/

void			get_token(t_fil *fil)
{
	char	*line;
	int		i;

	i = 0;
	if (fil->tok != NULL)
	{
		ft_arrdel(fil->tok->tok);
		free(fil->tok);
	}
	allocate_token(fil);
	fil->tok->tok = (char **)malloc(sizeof(char *) * (fil->tok->tv + 1));
	if (fil->tok->tok == NULL)
		exit(ERROR);
	fil->tok->tok[fil->tok->tv] = NULL;
	while (i < fil->tok->tv && get_next_line(0, &line))
	{
		fil->tok->tok[i] = ft_strdup(line);
		if (fil->tok->tok[i] == NULL)
			exit(ERROR);
		ft_strdel(&line);
		i++;
	}
}

/*
**	GET_GAME_INFO
**	reads first two lines of stdout
**	line 1: player number (to character O / X)
**	line 2: field size
**	then allocates fil->field size of field
*/

void			get_game_info(t_fil *fil)
{
	char	*line;
	char	**fsize;
	int		ret;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret == -1)
		exit(ERROR);
	fil->p = line[10] == '1' ? 'O' : 'X';
	fil->o = line[10] == '1' ? 'X' : 'O';
	ft_strdel(&line);
	get_next_line(0, &line);
	fsize = ft_strsplit(line, ' ');
	if (fsize == NULL)
		exit(ERROR);
	fil->fver = ft_atoi(fsize[1]);
	fil->fhor = ft_atoi(fsize[2]);
	ft_arrdel(fsize);
	ft_strdel(&line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:25:41 by jshim             #+#    #+#             */
/*   Updated: 2026/06/05 13:02:42 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_game *g)
{
	int	i;

	i = 0;
	if (!g->map)
		return ;
	while (i < g->map_h)
		free(g->map[i++]);
	free(g->map);
	g->map = NULL;
}

void	count_elements(t_game *g, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map_h)
	{
		j = -1;
		while (++j < g->map_w)
		{
			if (g->map[i][j] == 'P')
				(*p)++;
			else if (g->map[i][j] == 'E')
				(*e)++;
			else if (g->map[i][j] == 'C')
				(*c)++;
			else if (g->map[i][j] != '0' && g->map[i][j] != '1'
				&& g->map[i][j] != 'M')
				exit_error("Invalid Components in Map", g);
		}
	}
}

void	validate_components(t_game *g)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	count_elements(g, &p, &e, &c);
	if (p != 1)
		exit_error("# of Player must be 1", g);
	if (e != 1)
		exit_error("# of Exit must be 1", g);
	if (c < 1)
		exit_error("# of Collectibles must bigger than 1", g);
}

void	check_rectangle_and_walls(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map_h)
	{
		if ((int)ft_strlen(g->map[i]) != g->map_w)
			exit_error("Map is Not Rectangle", g);
		j = -1;
		while (++j < g->map_w)
		{
			if ((i == 0 || i == g->map_h - 1 || j == 0 || j == g->map_w - 1)
				&& g->map[i][j] != '1')
				exit_error("Map is Not Surrounded by Walls", g);
		}
	}
}

void	validate_map(t_game *g)
{
	check_rectangle_and_walls(g);
	validate_components(g);
	validate_path(g);
}

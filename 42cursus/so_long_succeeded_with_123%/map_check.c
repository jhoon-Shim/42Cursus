/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:58:42 by jshim             #+#    #+#             */
/*   Updated: 2026/06/05 13:00:58 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_game *g)
{
	if (x < 0 || y < 0 || x >= g->map_w || y >= g->map_h
		|| map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, g);
	flood_fill(map, x - 1, y, g);
	flood_fill(map, x, y + 1, g);
	flood_fill(map, x, y - 1, g);
}

int	is_beside_v(char **temp, int i, int j, t_game *g)
{
	if (i > 0 && temp[i - 1][j] == 'V')
		return (1);
	if (i < g->map_h - 1 && temp[i + 1][j] == 'V')
		return (1);
	if (j > 0 && temp[i][j - 1] == 'V')
		return (1);
	if (j < g->map_w - 1 && temp[i][j + 1] == 'V')
		return (1);
	return (0);
}

static char	*check_reachability(char **temp, t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map_h)
	{
		j = -1;
		while (++j < g->map_w)
		{
			if (g->map[i][j] == 'C' && temp[i][j] != 'V')
				return ("Item blocked by Exit or Wall");
			if (g->map[i][j] == 'E' && !is_beside_v(temp, i, j, g))
				return ("Exit is unreachable");
		}
	}
	return (NULL);
}

static void	free_temp(char **temp, int map_h)
{
	int	i;

	i = -1;
	while (++i < map_h)
		free(temp[i]);
	free(temp);
}

void	validate_path(t_game *g)
{
	char	**temp;
	char	*err;
	int		i;

	temp = malloc(sizeof(char *) * g->map_h);
	if (!temp)
		exit_error("Malloc failed", g);
	i = -1;
	while (++i < g->map_h)
	{
		temp[i] = ft_strdup(g->map[i]);
		if (!temp[i])
		{
			free_temp(temp, i);
			exit_error("Malloc failed", g);
		}
	}
	flood_fill(temp, g->p_x, g->p_y, g);
	err = check_reachability(temp, g);
	free_temp(temp, g->map_h);
	if (err)
		exit_error(err, g);
}

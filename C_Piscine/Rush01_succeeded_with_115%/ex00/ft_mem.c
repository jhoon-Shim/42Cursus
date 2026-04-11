/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:24:35 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 19:00:20 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**allocate_grid(int size)
{
	int	**grid;
	int	i;
	int	j;

	grid = (int **)malloc(sizeof(int *) * size);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < size)
	{
		grid[i] = (int *)malloc(sizeof(int) * size);
		if (!grid[i])
		{
			while (i > 0)
				free(grid[--i]);
			free(grid);
			return (NULL);
		}
		j = 0;
		while (j < size)
			grid[i][j++] = 0;
		i++;
	}
	return (grid);
}

void	free_grid(int **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	*allocate_clues(int size)
{
	int	*clues;

	clues = (int *)malloc(sizeof(int) * size * 4);
	if (!clues)
		return (NULL);
	return (clues);
}

void	cleanup_game(t_game *game)
{
	free_grid(game->grid, game->size);
	free(game->clues);
}

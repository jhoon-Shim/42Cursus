/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:23:19 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 19:00:29 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid_placement(t_game *game, int r, int c, int num)
{
	int	i;

	i = 0;
	while (i < game->size)
	{
		if (game->grid[r][i] == num)
			return (0);
		if (game->grid[i][c] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_cols(t_game *game)
{
	int	i;
	int	*temp_col;

	temp_col = (int *)malloc(sizeof(int) * game->size);
	if (!temp_col)
		return (0);
	i = 0;
	while (i < game->size)
	{
		copy_col(game, temp_col, i);
		if (game->clues[i] != count_visible(temp_col, game->size, 1) || \
			game->clues[game->size + i]
			!= count_visible(temp_col, game->size, -1))
		{
			free(temp_col);
			return (0);
		}
		i++;
	}
	free(temp_col);
	return (1);
}

int	check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size)
	{
		if (game->clues[2 * game->size + i] != \
				count_visible(game->grid[i], game->size, 1) || \
			game->clues[3 * game->size + i] != \
				count_visible(game->grid[i], game->size, -1))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_clues(t_game *game)
{
	if (!check_cols(game))
		return (0);
	if (!check_rows(game))
		return (0);
	return (1);
}

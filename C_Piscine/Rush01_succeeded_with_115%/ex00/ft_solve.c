/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:23:31 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 19:00:18 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	solve_grid(t_game *game, int index)
{
	int	r;
	int	c;
	int	num;

	if (index == game->size * game->size)
		return (check_clues(game));
	r = index / game->size;
	c = index % game->size;
	num = 1;
	while (num <= game->size)
	{
		if (is_valid_placement(game, r, c, num))
		{
			game->grid[r][c] = num;
			if (solve_grid(game, index + 1))
				return (1);
			game->grid[r][c] = 0;
		}
		num++;
	}
	return (0);
}

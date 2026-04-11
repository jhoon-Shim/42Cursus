/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:23:44 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 19:00:28 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_clue_elements(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= '9')
			count++;
		str++;
	}
	return (count);
}

int	get_n_size(int total_clues)
{
	int	size;

	if (total_clues % 4 != 0)
		return (0);
	size = total_clues / 4;
	if (size < 4 || size > 9)
		return (0);
	return (size);
}

int	init_game(t_game *game, char *arg_str)
{
	int	total_clues;

	total_clues = count_clue_elements(arg_str);
	game->size = get_n_size(total_clues);
	if (game->size == 0)
		return (0);
	game->clues = allocate_clues(game->size);
	if (!game->clues || !parse_clues(arg_str, game->clues, game->size))
	{
		if (game->clues)
			free(game->clues);
		return (0);
	}
	game->grid = allocate_grid(game->size);
	if (!game->grid)
	{
		free(game->clues);
		return (0);
	}
	return (1);
}

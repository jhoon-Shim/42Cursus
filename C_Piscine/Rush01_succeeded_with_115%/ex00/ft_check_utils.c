/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:23:05 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 19:00:32 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_visible(int *line, int size, int dir)
{
	int	i;
	int	count;
	int	max_height;

	count = 0;
	max_height = 0;
	if (dir == 1)
		i = 0;
	else
		i = size - 1;
	while (i >= 0 && i < size)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			count++;
		}
		if (dir == 1)
			i++;
		else
			i--;
	}
	return (count);
}

void	copy_col(t_game *game, int *temp_col, int c)
{
	int	r;

	r = 0;
	while (r < game->size)
	{
		temp_col[r] = game->grid[r][c];
		r++;
	}
}

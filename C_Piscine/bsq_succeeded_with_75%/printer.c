/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:14 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 17:47:09 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(char **map, t_map_info *info)
{
	int	i;

	i = 0;
	while (i < info->rows)
	{
		write(1, map[i], info->cols);
		write(1, "\n", 1);
		i++;
	}
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	free_dp_table(int **table, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (table[i])
			free(table[i]);
		i++;
	}
	free(table);
}

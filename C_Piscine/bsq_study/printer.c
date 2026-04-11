/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:14 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 14:54:00 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* printer.c */

#include "bsq.h"

/* 최종 맵 출력 */
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

/* 2차원 char 배열 (맵) 해제 */
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

/* 2차원 int 배열 (DP 테이블) 해제 */
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
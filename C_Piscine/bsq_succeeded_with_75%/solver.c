/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:18 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 17:47:13 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	fill_dp_table(char **map, t_map_info *info,
							int **dp, t_solution *sol)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->rows)
	{
		j = -1;
		while (++j < info->cols)
		{
			if (map[i][j] == info->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = ft_min(dp[i - 1][j], dp[i][j - 1],
						dp[i - 1][j - 1]) + 1;
			if (dp[i][j] > sol->size)
			{
				sol->size = dp[i][j];
				sol->row = i;
				sol->col = j;
			}
		}
	}
}

static int	**allocate_dp_table(t_map_info *info)
{
	int	**dp_table;
	int	i;

	dp_table = (int **)malloc(sizeof(int *) * info->rows);
	if (!dp_table)
		return (NULL);
	i = 0;
	while (i < info->rows)
	{
		dp_table[i] = (int *)malloc(sizeof(int) * info->cols);
		if (!dp_table[i])
		{
			free_dp_table(dp_table, i);
			return (NULL);
		}
		i++;
	}
	return (dp_table);
}

static void	draw_square(char **map, t_map_info *info, t_solution *sol)
{
	int	i;
	int	j;
	int	start_row;
	int	start_col;

	start_row = sol->row - sol->size + 1;
	start_col = sol->col - sol->size + 1;
	i = start_row;
	while (i <= sol->row)
	{
		j = start_col;
		while (j <= sol->col)
		{
			map[i][j] = info->full;
			j++;
		}
		i++;
	}
}

void	solve_bsq(char **map, t_map_info *info)
{
	int			**dp_table;
	t_solution	solution;

	dp_table = allocate_dp_table(info);
	if (!dp_table)
		return ;
	solution.size = 0;
	solution.row = 0;
	solution.col = 0;
	fill_dp_table(map, info, dp_table, &solution);
	if (solution.size > 0)
		draw_square(map, info, &solution);
	print_map(map, info);
	free_dp_table(dp_table, info->rows);
}

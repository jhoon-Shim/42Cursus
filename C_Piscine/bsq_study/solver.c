/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:18 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 14:54:04 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* solver.c */

#include "bsq.h"

/* DP 테이블을 채우고, 가장 큰 정사각형 정보를 solution에 저장 */
static void	fill_dp_table(char **map, t_map_info *info, int **dp, t_solution *sol)
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
			else if (i == 0 || j == 0) /* 첫 행 또는 첫 열 */
				dp[i][j] = 1;
			else
			{
				/* DP 공식: min(좌, 상, 좌상) + 1 */
				dp[i][j] = ft_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
			}
			/* 가장 큰 정사각형 갱신 (크기가 같으면 갱신 안 함 -> top, left 우선) */
			if (dp[i][j] > sol->size)
			{
				sol->size = dp[i][j];
				sol->row = i;
				sol->col = j;
			}
		}
	}
}

/* DP 테이블(2차원 정수 배열)을 할당 */
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
			/* 할당 실패 시, 이전까지 할당한 메모리 해제 */
			free_dp_table(dp_table, i);
			return (NULL);
		}
		i++;
	}
	return (dp_table);
}

/* 찾은 정사각형을 'full' 문자로 맵에 그리기 */
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

/* BSQ 문제 해결 메인 함수 */
void	solve_bsq(char **map, t_map_info *info)
{
	int			**dp_table;
	t_solution	solution;

	/* 1. DP 테이블 할당 */
	dp_table = allocate_dp_table(info);
	if (!dp_table)
		return ; /* 메모리 할당 실패 (이 경우 에러 처리가 필요할 수 있음) */
	
	/* 2. 솔루션 초기화 */
	solution.size = 0;
	solution.row = 0;
	solution.col = 0;

	/* 3. DP 테이블 채우기 및 해 찾기 */
	fill_dp_table(map, info, dp_table, &solution);

	/* 4. 맵에 정사각형 그리기 */
	if (solution.size > 0)
		draw_square(map, info, &solution);

	/* 5. 맵 출력 */
	print_map(map, info);

	/* 6. 메모리 해제 */
	free_dp_table(dp_table, info->rows);
}

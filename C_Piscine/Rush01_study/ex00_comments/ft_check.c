/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:52:21 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 17:56:59 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// 현재 위치에 num을 놓을 때, 행/열에 중복되는 숫자가 있는지 검사
int	is_valid_placement(int **grid, int r, int c, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (grid[r][i] == num)
			return (0);
		if (grid[i][c] == num)
			return (0);
		i++;
	}
	return (1);
}

// 한 방향에서 보이는 건물의 개수를 센다 (dir: 1 정방향, -1 역방향)
int	count_visible(int *line, int size, int dir)
{
	int	i;
	int	count;
	int	max_height;

	count = 0;
	max_height = 0;
	i = (dir == 1) ? 0 : size - 1;
	while (i >= 0 && i < size)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			count++;
		}
		i = i + dir;
	}
	return (count);
}

// 열(Column)을 복사하는 보조 함수 (N > 4일 때 필수)
void	copy_col(int **grid, int *temp_col, int c, int size)
{
	int	r;

	r = 0;
	while (r < size)
	{
		temp_col[r] = grid[r][c];
		r++;
	}
}

// 열(Column)에 대한 상/하 가시성 검사
int	check_cols(int **grid, int *clues, int size)
{
	int	i;
	int	*temp_col;

	temp_col = (int *)malloc(sizeof(int) * size);
	if (!temp_col)
		return (0);
	i = 0;
	while (i < size)
	{
		copy_col(grid, temp_col, i, size);
		// 상단 (clues[0]..clues[N-1]), 하단 (clues[N]..clues[2N-1])
		if (clues[i] != count_visible(temp_col, size, 1) || \
			clues[size + i] != count_visible(temp_col, size, -1))
		{
			free(temp_col);
			return (0);
		}
		i++;
	}
	free(temp_col);
	return (1);
}

// 행(Row)에 대한 좌/우 가시성 검사
int	check_rows(int **grid, int *clues, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		// 왼쪽 (clues[2N]..clues[3N-1]), 오른쪽 (clues[3N]..clues[4N-1])
		if (clues[2 * size + i] != count_visible(grid[i], size, 1) || \
			clues[3 * size + i] != count_visible(grid[i], size, -1))
			return (0);
		i++;
	}
	return (1);
}

// 최종 검증: 4*N 개의 모든 단서를 검사
int	check_clues(int **grid, int *clues, int size)
{
	if (!check_cols(grid, clues, size))
		return (0);
	if (!check_rows(grid, clues, size))
		return (0);
	return (1);
}
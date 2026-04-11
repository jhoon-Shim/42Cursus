/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:52:42 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 17:52:47 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// 백트래킹 메인 함수
int	solve_grid(int **grid, int index, int *clues, int size)
{
	int	r;
	int	c;
	int	num;

	// 기저 조건: N*N 개의 칸을 모두 채웠다면 최종 검증
	if (index == size * size)
		return (check_clues(grid, clues, size));
	
	r = index / size;
	c = index % size;

	num = 1;
	while (num <= size)
	{
		// 1. 중복이 없는지 확인
		if (is_valid_placement(grid, r, c, num, size))
		{
			grid[r][c] = num;
			// 2. 다음 칸으로 재귀 호출 (첫 번째 해답만 찾고 바로 종료)
			if (solve_grid(grid, index + 1, clues, size))
				return (1);
			// 3. 백트래킹: 실패 시 되돌리기
			grid[r][c] = 0;
		}
		num++;
	}
	return (0);
}
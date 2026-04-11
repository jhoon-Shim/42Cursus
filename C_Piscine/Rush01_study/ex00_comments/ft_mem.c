/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:08:09 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 18:08:12 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// N x N 그리드 동적 할당
int	**allocate_grid(int size)
{
	int	**grid;
	int	i;

	grid = (int **)malloc(sizeof(int *) * size);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < size)
	{
		grid[i] = (int *)malloc(sizeof(int) * size);
		if (!grid[i])
		{
			while (i > 0)
				free(grid[--i]);
			free(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

// 할당된 그리드 메모리 해제
void	free_grid(int **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

// N*N 크기의 clues 배열 동적 할당
int	*allocate_clues(int size)
{
	int	*clues;

	clues = (int *)malloc(sizeof(int) * size * size * 4);
	if (!clues)
		return (NULL);
	return (clues);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:53:01 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 18:07:07 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// 단서 문자열의 길이를 세는 보조 함수 (N을 추론하기 위해)
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

// 단서 개수로부터 N 크기를 계산
int	get_n_size(int total_clues)
{
	int	size;

	// 총 단서 개수는 N * 4 여야 함
	if (total_clues % 4 != 0)
		return (0);
	size = total_clues / 4;
	if (size < 4 || size > 9) // 문제의 필수 N=4와 보너스 N=9 제한
		return (0);
	return (size);
}

int	main(int argc, char **argv)
{
	int		**grid;
	int		*clues;
	int		size;
	int		total_clues;

	if (argc != 2)
	{
		ft_putstr(ERROR_MSG);
		ft_putstr("1\n");
		return (0);
	}
	total_clues = count_clue_elements(argv[1]);
	size = get_n_size(total_clues);
	if (size == 0)
	{
		ft_putstr(ERROR_MSG);
		ft_putstr("2\n");
		return (0);
	}
	
	clues = allocate_clues(size);
	if (!clues || !parse_clues(argv[1], clues, size))
	{
		ft_putstr(ERROR_MSG);
		ft_putstr("3\n");
		if (clues) free(clues);
		return (0);
	}

	grid = allocate_grid(size);
	if (!grid)
	{
		ft_putstr(ERROR_MSG);
		ft_putstr("4\n");
		free(clues);
		return (0);
	}

	if (solve_grid(grid, 0, clues, size))
		print_grid(grid, size);
	else
	{
		ft_putstr(ERROR_MSG);
		ft_putstr("5\n");
	}
	free_grid(grid, size);
	free(clues);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:51:53 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 17:56:58 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	if (*str >= '1' && *str <= '9') // 최대 9x9까지 고려하여 '9'로 변경
		res = *str - '0';
	return (res);
}

// 단서 문자열의 형식을 검사하는 보조 함수 (N*N*4 크기에 맞춰)
int	check_format(char *str, int *i, int total_clues)
{
	if (*str == '\0' || !(*str >= '1' && *str <= '9'))
		return (0);
	if (*i < total_clues - 1)
	{
		if (*(str + 1) != ' ')
			return (0);
	}
	else if (*(str + 1) != '\0')
		return (0);
	return (1);
}

// argv[1]을 단서(clues) 배열로 파싱 (size를 인자로 받음)
int	parse_clues(char *str, int *clues, int size)
{
	int	i;
	int	total_clues;

	i = 0;
	total_clues = size * 4;
	if (!str || !clues || total_clues < 16) // N<4는 허용하지 않음
		return (0);
	while (i < total_clues)
	{
		if (!check_format(str, &i, total_clues))
			return (0);
		clues[i] = ft_atoi(str);
		str++;
		if (i < total_clues - 1)
			str++; // 공백 건너뛰기
		i++;
	}
	return (1);
}

// N x N 격자 출력
void	print_grid(int **grid, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
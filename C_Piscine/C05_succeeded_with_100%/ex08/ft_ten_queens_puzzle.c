/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:25:48 by jshim             #+#    #+#             */
/*   Updated: 2025/11/04 01:48:42 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BOARD_SIZE 10

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	print_solution(char board[])
{
	int		i;
	char	digit_char;

	i = 0;
	while (i < BOARD_SIZE)
	{
		digit_char = board[i] + '0';
		write(1, &digit_char, 1);
		i++;
	}
	write(1, "\n", 1);
}

// 지리는 발견, 행의 차이와 열의 차이가 같다면 대각선에 위치
int	is_safe(char board[], int col, int row)
{
	int	prev_col;
	int	prev_row;

	prev_col = 0;
	while (prev_col < col)
	{
		prev_row = board[prev_col];
		if (prev_row == row)
			return (0);
		if (ft_abs(col - prev_col) == ft_abs(row - prev_row))
			return (0);
		prev_col++;
	}
	return (1);
}

void	solve_recursive(char board[], int *count, int col)
{
	int	row_try;

	if (col == BOARD_SIZE)
	{
		(*count)++;
		print_solution(board);
		return ;
	}
	row_try = 0;
	while (row_try < BOARD_SIZE)
	{
		if (is_safe(board, col, row_try))
		{
			board[col] = (char)row_try;
			solve_recursive(board, count, col + 1);
		}
		row_try++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[BOARD_SIZE];
	int		solution_count;
	int		i;

	i = 0;
	while (i < BOARD_SIZE)
	{
		board[i] = 0;
		i++;
	}
	solution_count = 0;
	solve_recursive(board, &solution_count, 0);
	return (solution_count);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_ten_queens_puzzle());
// }

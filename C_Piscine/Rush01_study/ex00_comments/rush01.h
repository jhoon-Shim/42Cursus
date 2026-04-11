/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:50:58 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 18:07:11 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR_MSG "Error\n"

// ft_mem.c (동적 할당 및 해제)
int		**allocate_grid(int size);
void	free_grid(int **grid, int size);
int		*allocate_clues(int size);

// ft_utils.c
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		parse_clues(char *str, int *clues, int size);
void	print_grid(int **grid, int size);

// ft_check.c
int		count_visible(int *line, int size, int dir);
int		check_clues(int **grid, int *clues, int size);
int		is_valid_placement(int **grid, int r, int c, int num, int size);

// ft_solve.c
int		solve_grid(int **grid, int index, int *clues, int size);

#endif
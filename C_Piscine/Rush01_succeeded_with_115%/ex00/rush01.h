/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:22:39 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 19:00:10 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR_MSG "Error\n"

typedef struct s_game
{
	int	**grid;
	int	*clues;
	int	size;
}	t_game;

int		count_clue_elements(char *str);
int		get_n_size(int total_clues);
int		init_game(t_game *game, char *arg_str);

int		**allocate_grid(int size);
void	free_grid(int **grid, int size);
int		*allocate_clues(int size);
void	cleanup_game(t_game *game);

void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		parse_clues(char *str, int *clues, int size);
void	print_grid(t_game *game);

int		count_visible(int *line, int size, int dir);
void	copy_col(t_game *game, int *temp_col, int c);

int		check_clues(t_game *game);
int		check_cols(t_game *game);
int		check_rows(t_game *game);
int		is_valid_placement(t_game *game, int r, int c, int num);

int		solve_grid(t_game *game, int index);

#endif

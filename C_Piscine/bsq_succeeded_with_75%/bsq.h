/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:06 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 17:47:06 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map_info
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map_info;

typedef struct s_solution
{
	int		size;
	int		row;
	int		col;
}	t_solution;

void	ft_putstr_err(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str, int len);
int		ft_min(int a, int b, int c);

char	**read_map(int fd, t_map_info *info);
int		parse_first_line(char *line, t_map_info *info);
int		validate_map(char **map, t_map_info *info);
char	*read_line(int fd);

void	solve_bsq(char **map, t_map_info *info);

void	print_map(char **map, t_map_info *info);

void	free_map(char **map, int rows);
void	free_dp_table(int **table, int rows);

# define MSG_MAP_ERROR "map error\n"

#endif
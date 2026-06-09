/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:32:44 by jshim             #+#    #+#             */
/*   Updated: 2026/06/05 04:21:25 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10000

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_w;
	void	*img_e;
	void	*img_p;
	void	*img_c;
	void	*img_x;
	void	*img_m[6];
	int		img_size;
	char	**map;
	int		map_w;
	int		map_h;
	int		p_x;
	int		p_y;
	int		moves;
	int		items;
	int		collected;
	int		frame;
}	t_game;

/* main.c */
int		close_window(t_game *g);

/* map_parse.c */
void	init_map(t_game *g, char *file);

/* map_check.c */
void	validate_map(t_game *g);
void	flood_fill(char **map, int x, int y, t_game *g);
int		is_beside_v(char **temp, int i, int j, t_game *g);
void	validate_path(t_game *g);
void	check_rectangle_and_walls(t_game *g);
void	count_elements(t_game *g, int *p, int *e, int *c);
void	validate_components(t_game *g);
void	validate_map(t_game *g);

/* graphics.c */
void	init_graphics(t_game *g);
void	render_map(t_game *g);

/* engine.c */
int		key_press(int keycode, t_game *g);
int		update_animation(t_game *g);

/* err */
void	exit_error(char *msg, t_game *g);
void	free_map(t_game *g);

#endif
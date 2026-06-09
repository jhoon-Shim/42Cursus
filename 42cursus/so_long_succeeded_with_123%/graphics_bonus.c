/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:44:19 by jshim             #+#    #+#             */
/*   Updated: 2026/06/05 13:01:25 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_enemy_imgs(t_game *g, int *sz)
{
	g->img_m[0] = mlx_xpm_file_to_image(g->mlx, "textures/enemy1.xpm", sz, sz);
	g->img_m[1] = mlx_xpm_file_to_image(g->mlx, "textures/enemy2.xpm", sz, sz);
	g->img_m[2] = mlx_xpm_file_to_image(g->mlx, "textures/enemy3.xpm", sz, sz);
	g->img_m[3] = mlx_xpm_file_to_image(g->mlx, "textures/enemy4.xpm", sz, sz);
	g->img_m[4] = mlx_xpm_file_to_image(g->mlx, "textures/enemy5.xpm", sz, sz);
	g->img_m[5] = mlx_xpm_file_to_image(g->mlx, "textures/enemy6.xpm", sz, sz);
}

void	init_graphics(t_game *g)
{
	int	sz;

	g->mlx = mlx_init();
	if (!g->mlx)
		exit_error("MLX init failed", g);
	g->img_w = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm",
			&g->img_size, &sz);
	g->img_e = mlx_xpm_file_to_image(g->mlx, "textures/empty.xpm", &sz, &sz);
	g->img_p = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm", &sz, &sz);
	g->img_c = mlx_xpm_file_to_image(g->mlx, "textures/item.xpm", &sz, &sz);
	g->img_x = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &sz, &sz);
	load_enemy_imgs(g, &sz);
	g->win = mlx_new_window(g->mlx, g->map_w * g->img_size,
			g->map_h * g->img_size, "so_long");
}

static void	put_tile(t_game *g, int i, int j)
{
	void	*img;

	mlx_put_image_to_window(g->mlx, g->win, g->img_e,
		j * g->img_size, i * g->img_size);
	img = NULL;
	if (g->map[i][j] == '1')
		img = g->img_w;
	else if (g->map[i][j] == 'P')
		img = g->img_p;
	else if (g->map[i][j] == 'C')
		img = g->img_c;
	else if (g->map[i][j] == 'E')
		img = g->img_x;
	else if (g->map[i][j] == 'M')
		img = g->img_m[(g->frame / 1000) % 6];
	if (img)
		mlx_put_image_to_window(g->mlx, g->win, img,
			j * g->img_size, i * g->img_size);
}

void	render_map(t_game *g)
{
	int		i;
	int		j;
	char	*moves;
	char	*str;

	i = 0;
	while (i < g->map_h)
	{
		j = 0;
		while (j < g->map_w)
		{
			put_tile(g, i, j);
			j++;
		}
		i++;
	}
	moves = ft_itoa(g->moves);
	str = ft_strjoin("MOVES: ", moves);
	free(moves);
	if (str)
	{
		mlx_string_put(g->mlx, g->win, 30, 30, 0xFFFFFF, str);
		free(str);
	}
}

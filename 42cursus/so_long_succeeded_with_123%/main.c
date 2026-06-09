/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:42:35 by jshim             #+#    #+#             */
/*   Updated: 2026/06/05 13:01:06 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *g)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (g->img_m[i])
			mlx_destroy_image(g->mlx, g->img_m[i]);
		i++;
	}
	if (g->img_w)
		mlx_destroy_image(g->mlx, g->img_w);
	if (g->img_e)
		mlx_destroy_image(g->mlx, g->img_e);
	if (g->img_p)
		mlx_destroy_image(g->mlx, g->img_p);
	if (g->img_c)
		mlx_destroy_image(g->mlx, g->img_c);
	if (g->img_x)
		mlx_destroy_image(g->mlx, g->img_x);
}

int	close_window(t_game *g)
{
	if (g->mlx)
	{
		destroy_images(g);
		mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	free_map(g);
	exit(0);
}

static void	init_struct(t_game *g)
{
	int	i;

	i = 0;
	while (i < 6)
		g->img_m[i++] = NULL;
	g->img_w = NULL;
	g->img_e = NULL;
	g->img_p = NULL;
	g->img_c = NULL;
	g->img_x = NULL;
	g->map = NULL;
	g->mlx = NULL;
	g->win = NULL;
	g->collected = 0;
	g->img_size = 0;
	g->map_h = 0;
	g->map_w = 0;
	g->moves = 0;
	g->items = 0;
	g->frame = 0;
}

static void	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || file[len - 5] == '/')
	{
		write(2, "Error\nInvalid file name\n", 24);
		exit(1);
	}
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		write(2, "Error\nInvalid file extension\n", 28);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
	{
		write(2, "Error\nvalid format = ./so_long maps/map.ber\n", 44);
		return (-1);
	}
	check_extension(argv[1]);
	init_struct(&g);
	init_map(&g, argv[1]);
	validate_map(&g);
	init_graphics(&g);
	render_map(&g);
	mlx_key_hook(g.win, key_press, &g);
	mlx_hook(g.win, 17, 0, close_window, &g);
	mlx_loop_hook(g.mlx, update_animation, &g);
	mlx_loop(g.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:44:40 by jshim             #+#    #+#             */
/*   Updated: 2026/06/05 03:58:31 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_animation(t_game *g)
{
	g->frame++;
	if (g->frame > 6000)
		g->frame = 0;
	if (g->frame % 1000 == 0)
		render_map(g);
	return (0);
}

static void	move_to(t_game *g, int nx, int ny)
{
	if (g->map[ny][nx] == '1')
		return ;
	if (g->map[ny][nx] == 'M')
		exit_error("Game Over! Hit by Enemy", g);
	if (g->map[ny][nx] == 'E')
	{
		if (g->collected == g->items)
		{
			ft_printf("Total moves: %d\nClear!\n", g->moves + 1);
			close_window(g);
		}
		return ;
	}
	if (g->map[ny][nx] == 'C')
		g->collected++;
	g->map[g->p_y][g->p_x] = '0';
	g->map[ny][nx] = 'P';
	g->p_x = nx;
	g->p_y = ny;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	render_map(g);
}

int	key_press(int keycode, t_game *g)
{
	if (keycode == 65307)
		close_window(g);
	else if (keycode == 119)
		move_to(g, g->p_x, g->p_y - 1);
	else if (keycode == 115)
		move_to(g, g->p_x, g->p_y + 1);
	else if (keycode == 97)
		move_to(g, g->p_x - 1, g->p_y);
	else if (keycode == 100)
		move_to(g, g->p_x + 1, g->p_y);
	return (0);
}

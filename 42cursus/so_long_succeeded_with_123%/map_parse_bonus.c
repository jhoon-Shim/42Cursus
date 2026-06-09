/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:43:24 by jshim             #+#    #+#             */
/*   Updated: 2026/06/05 13:00:10 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_error(char *msg, t_game *g)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	close_window(g);
}

static void	set_dimensions(t_game *g, char *buf, int rb)
{
	int	i;

	g->map_w = 0;
	while (buf[g->map_w] && buf[g->map_w] != '\n')
		g->map_w++;
	g->map_h = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			g->map_h++;
		i++;
	}
	if (rb > 0 && buf[rb - 1] != '\n')
		g->map_h++;
}

static void	fill_map_row(t_game *g, char *buf, int i, int *k)
{
	int	j;
	int	len;

	len = 0;
	while (buf[*k + len] && buf[*k + len] != '\n')
		len++;
	g->map[i] = malloc(len + 1);
	if (!g->map[i])
		exit_error("Malloc failed", g);
	j = -1;
	while (++j < len)
	{
		if (buf[*k] == 'P')
			g->p_x = j;
		if (buf[*k] == 'P')
			g->p_y = i;
		if (buf[*k] == 'C')
			g->items++;
		g->map[i][j] = buf[(*k)++];
	}
	g->map[i][j] = '\0';
	if (buf[*k] == '\n')
		(*k)++;
}

void	init_map(t_game *g, char *file)
{
	int		fd;
	int		rb;
	int		i;
	int		k;
	char	buf[BUFFER_SIZE];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error("File open failed", g);
	rb = read(fd, buf, BUFFER_SIZE - 1);
	if (rb <= 0)
	{
		close(fd);
		exit_error("File read failed", g);
	}
	buf[rb] = '\0';
	close(fd);
	set_dimensions(g, buf, rb);
	g->map = malloc(sizeof(char *) * g->map_h);
	if (!g->map)
		exit_error("Malloc failed", g);
	i = 0;
	k = 0;
	while (i < g->map_h)
		fill_map_row(g, buf, i++, &k);
}

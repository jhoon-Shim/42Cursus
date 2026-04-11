/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yepark <yepark@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:16 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 22:31:44 by yepark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_line(int fd)
{
	char	*line;
	char	buf[1];
	int		bytes_read;
	int		i;

	line = (char *)malloc(sizeof(char) * 1000001);
	if (!line)
		return (NULL);
	i = 0;
	while (1)
	{
		bytes_read = read(fd, buf, 1);
		if (bytes_read <= 0 || buf[0] == '\n')
			break ;
		line[i++] = buf[0];
		if (i >= 1000000)
			break ;
	}
	line[i] = '\0';
	if (bytes_read <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	parse_first_line(char *line, t_map_info *info)
{
	int	len;

	len = ft_strlen(line);
	if (len < 4)
		return (0);
	info->full = line[len - 1];
	info->obstacle = line[len - 2];
	info->empty = line[len - 3];
	if (info->empty >= '0' && info->empty <= '9')
		return (0);
	if (info->empty < 32 || info->empty > 126
		|| info->obstacle < 32 || info->obstacle > 126
		|| info->full < 32 || info->full > 126)
		return (0);
	if (info->empty == info->obstacle || info->empty == info->full \
		|| info->obstacle == info->full)
		return (0);
	info->rows = ft_atoi(line, len - 3);
	if (info->rows <= 0)
		return (0);
	return (1);
}

int	validate_map(char **map, t_map_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->rows)
	{
		if (map[i] == NULL)
			return (0);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != info->empty && map[i][j] != info->obstacle)
				return (0);
			j++;
		}
		if (i == 0)
			info->cols = j;
		else if (info->cols != j)
			return (0);
		i++;
	}
	if (info->cols == 0)
		return (0);
	return (1);
}

static int	read_map_body(int fd, char **map, t_map_info *info)
{
	int	i;

	i = 0;
	while (i < info->rows)
	{
		map[i] = read_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	if (i != info->rows || !validate_map(map, info))
	{
		free_map(map, i);
		return (0);
	}
	return (1);
}

char	**read_map(int fd, t_map_info *info)
{
	char	**map;
	char	*first_line;

	first_line = read_line(fd);
	if (first_line == NULL || !parse_first_line(first_line, info))
	{
		if (first_line)
			free(first_line);
		return (NULL);
	}
	free(first_line);
	map = (char **)malloc(sizeof(char *) * info->rows);
	if (!map)
		return (NULL);
	if (!read_map_body(fd, map, info))
		return (NULL);
	return (map);
}

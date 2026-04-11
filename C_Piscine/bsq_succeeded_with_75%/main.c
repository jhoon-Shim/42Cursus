/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:12 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 17:47:07 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process_map(int fd)
{
	t_map_info	info;
	char		**map;

	map = read_map(fd, &info);
	if (map == NULL)
	{
		ft_putstr_err(MSG_MAP_ERROR);
		return ;
	}
	solve_bsq(map, &info);
	free_map(map, info.rows);
}

void	process_files(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_err(MSG_MAP_ERROR);
		}
		else
		{
			process_map(fd);
			close(fd);
		}
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		process_map(0);
	}
	else
	{
		process_files(argc, argv);
	}
	return (0);
}

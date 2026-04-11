/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:12 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 14:53:55 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main.c */

#include "bsq.h"

/* ** 주어진 파일 디스크립터(fd)로부터 맵을 읽고, 풀고, 출력합니다.
** 에러 발생 시 "map error"를 출력합니다.
*/
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

/* 인자(파일)들을 순회하며 처리 */
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
		/* 여러 파일 처리 시, 각 출력 사이에 빈 줄 삽입 */
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		/* 인자가 없으면 표준 입력(fd=0)에서 읽기 */
		process_map(0);
	}
	else
	{
		/* 인자가 있으면 파일 순회 */
		process_files(argc, argv);
	}
	return (0);
}
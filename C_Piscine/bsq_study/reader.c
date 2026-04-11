/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:16 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 14:54:01 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* reader.c */

#include "bsq.h"

/* ** 간소화된 read_line 구현: 
** 이 프로젝트의 복잡성을 고려할 때, 
** 한 줄의 최대 길이를 가정하거나 (예: 10000)
** 매우 큰 버퍼(예: 8MB)로 파일 전체를 읽는 것이 일반적입니다.
** 여기서는 '한 줄씩' 읽는 로직을 구현합니다.
*/
char	*read_line(int fd)
{
	char	*line;
	char	buf[1];
	int		bytes_read;
	int		i;

	/* 최대 1MB 라인까지 허용 */
	line = (char *)malloc(sizeof(char) * 1000001);
	if (!line)
		return (NULL);
	i = 0;
	bytes_read = read(fd, buf, 1);
	while (bytes_read > 0)
	{
		if (buf[0] == '\n')
			break ;
		line[i++] = buf[0];
		if (i >= 1000000) /* 버퍼 오버플로우 방지 */
			break;
		bytes_read = read(fd, buf, 1);
	}
	line[i] = '\0';
	/* bytes_read가 0이고 i가 0이면 (파일 끝) NULL 반환 */
	if (bytes_read <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* 첫 번째 라인 파싱 */
int	parse_first_line(char *line, t_map_info *info)
{
	int	len;

	len = ft_strlen(line);
	if (len < 4) /* "1.ox" 보다 짧으면 무조건 에러 */
		return (0);
	info->full = line[len - 1];
	info->obstacle = line[len - 2];
	info->empty = line[len - 3];
	/* 세 문자가 달라야 함 */
	if (info->empty == info->obstacle || info->empty == info->full \
		|| info->obstacle == info->full)
		return (0);
	/* 숫자는 '0'에서 '9' */
	info->rows = ft_atoi(line, len - 3);
	/* 줄 수는 1 이상이어야 함 */
	if (info->rows <= 0)
		return (0);
	return (1);
}

/* 맵 유효성 검사 (두 번째 줄부터) */
int	validate_map(char **map, t_map_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->rows)
	{
		if (map[i] == NULL) /* 맵 줄 수가 모자람 */
			return (0);
		j = 0;
		while (map[i][j])
		{
			/* 맵 문자는 empty나 obstacle이어야 함 */
			if (map[i][j] != info->empty && map[i][j] != info->obstacle)
				return (0);
			j++;
		}
		/* 모든 줄의 길이가 같아야 함 */
		if (i == 0)
			info->cols = j;
		else if (info->cols != j)
			return (0);
		i++;
	}
	/* 맵은 최소 1x1 이어야 함 (cols > 0) */
	if (info->cols == 0)
		return (0);
	return (1);
}

/* 맵 읽기 메인 함수 */
char	**read_map(int fd, t_map_info *info)
{
	char	**map;
	char	*first_line;
	int		i;

	first_line = read_line(fd);
	if (first_line == NULL || !parse_first_line(first_line, info))
	{
		if (first_line)
			free(first_line);
		return (NULL);
	}
	free(first_line); /* 첫 줄은 파싱 후 해제 */
	map = (char **)malloc(sizeof(char *) * info->rows);
	if (!map)
		return (NULL);
	i = 0;
	while (i < info->rows)
	{
		map[i] = read_line(fd);
		if (map[i] == NULL) /* 맵을 다 읽기 전에 파일이 끝남 */
			break ;
		i++;
	}
	/* 맵 유효성 검사 */
	if (i != info->rows || !validate_map(map, info))
	{
		free_map(map, i);
		return (NULL);
	}
	return (map);
}
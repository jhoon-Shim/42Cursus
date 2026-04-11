/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:06 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 14:53:53 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* bsq.h */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h> // read, write
# include <stdlib.h> // malloc, free
# include <fcntl.h>  // open, close

/*
** 맵의 기본 정보를 저장하는 구조체
** rows: 줄 수
** cols: 각 줄의 칸 수 (너비)
** empty: 빈칸 문자
** obstacle: 장애물 문자
** full: 채움 문자
*/
typedef struct s_map_info
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map_info;

/*
** DP 테이블에서 찾은 가장 큰 정사각형의 정보
** size: 정사각형의 크기
** row: 정사각형의 우측 하단 모서리의 행 (y)
** col: 정사각형의 우측 하단 모서리의 열 (x)
*/
typedef struct s_solution
{
	int		size;
	int		row;
	int		col;
}	t_solution;

/* --- 유틸리티 함수 (utils.c) --- */
void	ft_putstr_err(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str, int len);
int		ft_min(int a, int b, int c);

/* --- 리더 및 파서 함수 (reader.c) --- */
char	**read_map(int fd, t_map_info *info);
int		parse_first_line(char *line, t_map_info *info);
int		validate_map(char **map, t_map_info *info);
char	*read_line(int fd);

/* --- 솔버 함수 (solver.c) --- */
void	solve_bsq(char **map, t_map_info *info);

/* --- 프린터 함수 (printer.c) --- */
void	print_map(char **map, t_map_info *info);

/* --- 메모리 해제 --- */
void	free_map(char **map, int rows);
void	free_dp_table(int **table, int rows);

/* --- 에러 메시지 --- */
# define MSG_MAP_ERROR "map error\n"

#endif
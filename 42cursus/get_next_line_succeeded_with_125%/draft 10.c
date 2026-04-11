/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:48:08 by jshim             #+#    #+#             */
/*   Updated: 2026/03/04 18:47:52 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*read_until_oneline(char *str[], int fd)
{
	char	*buf;
	int		idx;

	while (!strchr(str[fd], '\n'))
	{
		buf = (char *) malloc (BUFFER_SIZE + 1);
		if (!buf)
		{
			free(str[fd]);
			return (NULL);
		}
		idx = read(fd, buf, BUFFER_SIZE);
		buf[idx] = 0;
		if (idx <= 0)
		{
			free(buf);
			return (str[fd]);
		}
		strcat(str[fd], buf);
		printf("buf =%s\nstr[fd] =%s\n", buf, str[fd]);
		printf("backup[%d]의 길이 =%d\n\n", fd, (int) strlen(str[fd]));
		free(buf);
	}
	return (str[fd]);
}

char	*extract_oneline(char *str[], int fd)
{
	int		idx;
	char	*oneline;

	idx = 0 ;
	while (str[fd][idx] != '\n' && str[fd][idx] != 0)
		idx ++;
	oneline = strndup(str[fd], idx + 1);
	if (!oneline)
		return (NULL);
	if (oneline[0] == 0)
		return (NULL);
	str[fd] += idx + 1;
	return (oneline);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*oneline;

	if (!backup[fd])
	{
		backup[fd] = (char *) malloc(2 * BUFFER_SIZE + 1);
		if (!backup[fd])
			return (NULL);
		backup[fd][0] = 0;
	}
	backup[fd] = read_until_oneline(backup, fd);
	oneline = extract_oneline(backup, fd);
	return (oneline);
}

// 발견한 문제 
// 1. 한 줄의 길이 > backup[fd] ?
// 2. backup[fd] 의 시작주소를 바꿔가면서 하고 있음. 메모리 비효율 & free 오류
// 3. oneline 과 backup[fd] 를 free 할 수 없는 구조.

int main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line1;
	char	*line2;
	char	*line3;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	while (1)
	{

		line1 = get_next_line(fd1);
		if(line1 == NULL)
		{
			free(line1);
			break;
		}
		line2 = get_next_line(fd2);
		if(line2 == NULL)
		{
			free(line1);
			break;
		}
		line3 = get_next_line(fd3);
		if(line3 == NULL)
		{
			free(line1);
			break;
		}

		printf("\n1 START ");
		printf("%s", line1);
		printf("1 END\n");

		printf("\n2 START ");
		printf("%s", line2);
		printf("2 END\n");

		printf("\n3 START ");
		printf("%s", line3);
		printf("3 END\n");

		free(line1);
		free(line2);
		free(line3);
	}

	close(fd1);
	close(fd2);
	close(fd3);
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:48:08 by jshim             #+#    #+#             */
/*   Updated: 2026/03/04 10:54:04 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*extract_oneline(char *str[], int fd)
{
	int		idx;
	char	*oneline;

	idx = 0 ;
	while (str[fd][idx] != '\n' && str[fd][idx] != 0)
		idx ++;
	oneline = strndup(str[fd], idx + 1);
	if (!oneline || oneline[0] == 0)
		return (NULL);
	str[fd] += idx + 1;
	return (oneline);
}

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
			break ;
		strcat(str[fd], buf);
	}
	return (str[fd]);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*oneline;

	if (!backup[fd])
	{
		backup[fd] = (char *) malloc(1);
		if (!backup[fd])
			return (NULL);
		backup[fd][0] = 0;
	}
	backup[fd] = read_until_oneline(backup, fd);
	oneline = extract_oneline(backup, fd);
	return (oneline);
}

// static 으로 선언하니까 다른 함수에서 가도 인덱스 값이 기억되고 있어서
// 매우 편하네. 원래는 인자를 하나 더받아서 하던가 해야하는데
// 개사기네

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

	while ((line1 = get_next_line(fd1)) != NULL &&
			(line2 = get_next_line(fd2)) != NULL &&
			(line3 = get_next_line(fd3)) != NULL)
	{
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

	free(line1);
	free(line2);
	free(line3);
	
	return (0);
}
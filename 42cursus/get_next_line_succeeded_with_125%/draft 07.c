/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:48:08 by jshim             #+#    #+#             */
/*   Updated: 2026/03/04 10:05:45 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*extract_oneline (char *str[], int fd)
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

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*oneline;
	char		*buf;
	int			idx;

	if (!backup[fd])
	{
		backup[fd] = (char *) malloc(1);
		if (!backup[fd])
			return (NULL);
		backup[fd][0] = 0;
	}
	while (!strchr(backup[fd], '\n'))
	{
		buf = (char *) malloc (BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		idx = read(fd, buf, BUFFER_SIZE);
		buf[idx] = 0;
		if (idx <= 0)
			break ;
		strcat (backup[fd], buf);
	}
	oneline = extract_oneline(backup, fd);
	return (oneline);
}

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
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
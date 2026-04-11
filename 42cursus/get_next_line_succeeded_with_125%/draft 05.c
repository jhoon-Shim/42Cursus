#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*oneline;
	char		*buf;
	int			idx;
	int			lastidx;

	if (!backup[fd])
	{
		backup[fd] = (char *) malloc(1);
		backup[fd][0] = 0;
	}

	while (!strchr(backup[fd], '\n'))
	{
		buf = (char *) malloc (BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		lastidx = read(fd, buf, BUFFER_SIZE);
		buf[lastidx] = 0;
		if (lastidx <= 0)
			break;
		strcat(backup[fd], buf);
	}

	idx = 0;
	while (backup[fd][idx] != '\n' && backup[fd][idx] != 0)
		idx++;
	
	oneline = strndup(backup[fd], idx + 1);
	if (!oneline || oneline[0] == 0)
		return (NULL);
	backup[fd] += idx + 1;
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

	while ((line1 = get_next_line(fd1)) != '\0' &&
			(line2 = get_next_line(fd2)) != '\0' &&
			(line3 = get_next_line(fd3)) != '\0')
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
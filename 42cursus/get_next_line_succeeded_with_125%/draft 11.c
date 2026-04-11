#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char	*backup[1024];
	char	*oneline;
	char	*buf;
	int		idx;

	oneline = 0;

	while (!oneline)
	{
		buf = (char *) malloc (BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		idx = read(fd, buf, BUFFER_SIZE);
		
		if (idx <0)
		{
			free(backup[fd]);
			free(buf);
			return (NULL);
		}
		
		else if (idx = 0)
		{
			oneline = strdup(backup);
			free(backup[fd]);
			free(buf);
			return (oneline);
		}
		
		else
		{
			buf[idx] = 0;
			backup[fd] = 0;
		}
	}
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
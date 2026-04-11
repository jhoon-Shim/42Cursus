#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*oneline;
	int			idx;
	int			lastidx;

	if (backup[fd] == NULL) // backup[fd] 가 가르키는 값이 NULL 일때	
	{
		backup[fd] = (char *) malloc (BUFFER_SIZE + 1);
		if (!backup[fd])
			return (NULL);
		lastidx = read(fd, backup[fd], BUFFER_SIZE);

		printf("lastidx = %d \n", lastidx);
		printf("BEFORE backup[%d] = %s \n", fd, backup[fd]);

		if (lastidx <= 0)
		{
			free(backup[fd]);
			return (NULL);
		}	
		backup[fd][lastidx] = 0;
	}
	
	idx = 0;
	while (backup[fd][idx] != '\n' && backup[fd][idx + 1] != '\0')
		idx ++;

	printf("idx = %d\n", idx);
	printf("backup = %s\n", backup[fd]);

	oneline = strndup(backup[fd], idx + 1);
	if (!oneline)
		free (oneline);
	backup[fd] += idx + 1;
	
	printf("oneline = %s \n", oneline);
	printf("AFTER backup[%d] = %s \n", fd, backup[fd]);

	return (oneline);
}

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	for (int j = 0; j<20; j++)
	
	{
		line = get_next_line(fd);
		printf("\n****START****\n");
		printf("%s", line);
		printf("\n****END****\n");
	}

	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("\nSTART\n");
	// 	printf("%s", line);
	// 	printf("\nEND\n");
	// }

	close(fd);
	return (0);
}
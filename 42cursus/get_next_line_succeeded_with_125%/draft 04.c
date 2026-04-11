#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*oneline;
	char		*cat;
	int			idx;
	int			lastidx;

	if (!backup[fd])
	{
		backup[fd] = (char *) malloc (BUFFER_SIZE + 1);
		if (!backup[fd])
			return (NULL);
		backup[fd][0] = '\0';	
	}

	if (!strchr(backup[fd], '\n'))
	{
		cat = (char *) malloc (BUFFER_SIZE + 1);
		if (!cat)
			return (NULL);
		lastidx = read(fd, cat, BUFFER_SIZE);
		if (lastidx <= 0)
			return (backup[fd]);
		cat[lastidx] = 0;
		strcat(backup[fd], cat);
	}

	if (strchr(backup[fd], '\n'))
	{
		idx = strchr(backup[fd], '\n') - backup[fd];
		oneline = strndup(backup[fd], idx + 1);
		if (!oneline)
			return (NULL);
		backup[fd] += idx + 1;
		return (oneline);
	}
}

// 시발 buffer 사이즈가 작아서 읽었는데 개행이 없으면 그냥 널 반환하고 끝이네
// 한줄 모일떄까지 기다려야하는데 말이야 쉬바.
// 반복문 돌리면 되겠네 아싸 

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	// for (int j = 0; j<20; j++)
	
	// {
	// 	line = get_next_line(fd);
	// 	printf("\n****START****\n");
	// 	printf("%s", line);
	// 	printf("\n****END****\n");
	// }

	while ((line = get_next_line(fd)) != '\0')
	{
		printf("\nSTART\n");
		printf("%s", line);
		printf("\nEND\n");
	}

	close(fd);
	return (0);
}
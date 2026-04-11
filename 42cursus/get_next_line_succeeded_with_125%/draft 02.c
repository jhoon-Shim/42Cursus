#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*str;
	char		*buf;
	int			i;

	// 구조체배열로 짜면 된다, 크기는 1024 
	int			length;

	i = 1;

	if (backup != NULL)
	{
		printf("\n\n백없이 있다면\n\n");

		while (*(backup + i) != '\0' && *(backup + i) != '\n')
			i ++;
		
		printf("1st i = %d\n", i);
		
		printf("전) backup = %s \n", backup);

		str = strndup (backup, i + 1);

		backup += i + 1;
		
		if (*(backup + 1) == '\0')
			backup = NULL;

		printf("후) backup = %s \n", backup);

		return (str);
	}

	else 
	{
		printf("\n\n백업이 없다면\n\n");

		buf = malloc (BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		// *(buf + BUFFER_SIZE) = '\0';
		int t = read(fd, buf, BUFFER_SIZE);
		printf("read: %d\n", t);
		buf[t] = 0;
		if (t <= 0)
			return (NULL);
		
		length = strlen(buf);

		while (*(buf + i) != '\0' && *(buf + i) != '\n')
			i ++;

		printf("2st i = %d\n", i);
		
		str = strndup (buf, i + 1);

		if (*(buf + i) != '\0')
			backup = strndup(buf + i + 1, length - i);

		printf("backup = %s \n", backup);

		return (str);
	}
}

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	for (int j = 0; j<20; j++)
	
	// {
	// 	line = get_next_line(fd);
	// 	printf("**START**");
	// 	printf("%s", line);
	// 	free(line);
	// 	printf("**END**");

	// }

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("\nSTART\n");
		printf("%s", line);
		free(line);
		printf("\nEND\n");
	}

	close(fd);
	return (0);
}

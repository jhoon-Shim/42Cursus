#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*str;
	char		*buf;
	int			flag;
	int			i;

	i = 0;
	str = malloc (BUFFER_SIZE + 1);
	buf = malloc (BUFFER_SIZE + 1);
	
	if (!str || !buf)
		return (NULL);

	flag = read(fd, buf, BUFFER_SIZE);
	if (flag < 0)
		return (NULL);

	printf("buf = %s\n", buf);

	if (backup == NULL)
	{
		backup = malloc (BUFFER_SIZE + 1);
		if (!backup)
			return (NULL);

		printf("2\n");
		
		while ((buf + i) != NULL && *(buf + i) != '\n')
		{
			printf("1i = %d\n",i);

			i ++;
		}
		printf("1i = %d\n",i);
		
		strncpy(str,buf,i+1);
		
		buf += i;

		printf("4\n");

		if (!buf)
			strncpy(backup, buf, strlen(buf));

		return (str);
	}

	printf("5\n");
	
	while ((backup +i ) != NULL && *(backup + i) !='\n')
		i ++;
	
	printf("2i = %d\n",i);

	str = strncpy(str, backup, i+1);
	backup += i;
	
	return (str);
}

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
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

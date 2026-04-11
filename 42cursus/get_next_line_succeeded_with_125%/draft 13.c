#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length])
		length ++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	join = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i ++;
	}
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		join[i] = s2[i - ft_strlen(s1)];
		i ++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

char	*read_until_oneline(char *str[], int fd)
{
	char	*buf;
	int		idx;
	char	*tmp;

	while (!ft_strchr(str[fd], '\n'))
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
			break ;
		}
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		free(buf);
	}
	return (str[fd]);
}

char	*extract_oneline(char *str[], int fd)
{
	int		idx;
	char	*oneline;
	char	*tmp;

	idx = 0 ;
	while (str[fd][idx] != '\n' && str[fd][idx] != 0)
		idx ++;
	oneline = strndup(str[fd], idx + 1);
	if (!oneline)
		return (NULL);
	if (oneline[0] == 0)
	{
		free(oneline);
		oneline = NULL;
	}
	tmp = strdup(str[fd]+ idx +(str[fd][idx] == '\n'));
	free(str[fd]);
	str[fd] = tmp;
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
	if(backup[fd] && *backup[fd] == '\0')
	{
		free(backup[fd]);
		backup[fd] = NULL;
	}
	return (oneline);
}

int main(void)
{
	int		fd1, fd2, fd3, fd4;
	char	*line1, *line2, *line3, *line4;
	int		d1 = 1, d2 = 1, d3 = 1, d4 = 1; 

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);

	while (d1 || d2 || d3 || d4) 
	{
		if (d1 && (line1 = get_next_line(fd1)))
		{
			printf("1: %s", line1);
			free(line1);
		}
		else d1 = 0;

		if (d2 && (line2 = get_next_line(fd2)))
		{
			printf("2: %s", line2);
			free(line2);
		}
		else d2 = 0;

		if (d3 && (line3 = get_next_line(fd3)))
		{
			printf("3: %s", line3);
			free(line3);
		}
		else d3 = 0;

		if (d4 && (line4 = get_next_line(fd4)))
		{
			printf("4: %s", line4);
			free(line4);
		}
		else d4 = 0;
	}

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}

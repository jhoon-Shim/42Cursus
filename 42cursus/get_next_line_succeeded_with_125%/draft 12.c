/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:48:08 by jshim             #+#    #+#             */
/*   Updated: 2026/03/05 01:27:32 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (NULL);
	}
	tmp = strdup(str[fd]+ idx +1);
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
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		if(line1 == NULL || line2 == NULL || line3 == NULL)
		{
			free(line1);
			free(line2);
			free(line3);
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
// char	*read_until_oneline(char *str[], int fd)
// {
// 	char	*buf;
// 	int		idx;
// 	char	*tmp;

// 	while (str[fd] && !ft_strchr(str[fd], '\n'))
// 	{
// 		buf = (char *) malloc (BUFFER_SIZE + 1);
// 		if (!buf)
// 		{
// 			free(str[fd]);
// 			return (NULL);
// 		}
// 		idx = read(fd, buf, BUFFER_SIZE);
// 		if (idx <= 0)
// 		{
// 			free(buf);
// 			break ;
// 		}
// 		buf[idx] = '\0';
// 		tmp = str[fd];
// 		str[fd] = ft_strjoin(tmp, buf);
// 		free(tmp);
// 		free(buf);
// 	}
// 	return (str[fd]);
// }
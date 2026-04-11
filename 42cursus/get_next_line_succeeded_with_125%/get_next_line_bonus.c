/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:16:22 by jshim             #+#    #+#             */
/*   Updated: 2026/03/05 19:00:40 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_until_oneline(char *str[], int fd)
{
	char	*buf;
	int		idx;
	char	*tmp;

	while (str[fd] && !ft_strchr(str[fd], '\n'))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (free(str[fd]), str[fd] = NULL, NULL);
		idx = read(fd, buf, BUFFER_SIZE);
		if (idx < 0)
			return (free(buf), free(str[fd]), str[fd] = NULL, NULL);
		if (idx == 0)
			return (free(buf), str[fd]);
		buf[idx] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		free(buf);
		if (!str[fd])
			return (NULL);
	}
	return (str[fd]);
}

char	*extract_oneline(char *str[], int fd)
{
	int		idx;
	char	*oneline;
	char	*tmp;

	if (!str[fd])
		return (NULL);
	idx = 0 ;
	while (str[fd][idx] != '\n' && str[fd][idx] != 0)
		idx ++;
	oneline = ft_strndup(str[fd], idx + (str[fd][idx] == '\n'));
	if (!oneline)
		return (NULL);
	if (oneline[0] == 0)
	{
		free(oneline);
		oneline = NULL;
	}
	tmp = ft_strdup(str[fd] + idx + (str[fd][idx] == '\n'));
	free(str[fd]);
	str[fd] = tmp;
	return (oneline);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*oneline;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup[fd])
	{
		backup[fd] = (char *) malloc(1);
		if (!backup[fd])
			return (NULL);
		backup[fd][0] = '\0';
	}
	backup[fd] = read_until_oneline(backup, fd);
	oneline = extract_oneline(backup, fd);
	if (backup[fd] && *backup[fd] == '\0')
	{
		free(backup[fd]);
		backup[fd] = NULL;
	}
	return (oneline);
}

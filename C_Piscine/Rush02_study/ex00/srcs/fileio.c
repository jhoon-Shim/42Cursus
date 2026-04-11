/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.campus>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:00:00 by you               #+#    #+#             */
/*   Updated: 2025/11/08 15:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	reader_init(t_reader *r)
{
	r->mem = NULL;
	r->len = 0;
	r->cap = 0;
}

static bool	reader_grow(t_reader *r, size_t need)
{
	char	*tmp;
	size_t	i;
	size_t	ncap;

	if (r->cap == 0)
		ncap = 8192;
	else
		ncap = r->cap * 2;
	while (ncap < need)
		ncap *= 2;
	tmp = (char *)malloc(ncap);
	if (!tmp)
		return (false);
	i = 0;
	while (i < r->len)
	{
		tmp[i] = r->mem[i];
		i++;
	}
	free(r->mem);
	r->mem = tmp;
	r->cap = ncap;
	return (true);
}

static bool	reader_append(t_reader *r, const char *buf, size_t n)
{
	size_t	i;
	size_t	need;

	need = r->len + n + 1;
	if (need > r->cap)
		if (!reader_grow(r, need))
			return (false);
	i = 0;
	while (i < n)
	{
		r->mem[r->len] = buf[i];
		r->len++;
		i++;
	}
	return (true);
}

static bool	read_loop(int fd, t_reader *r)
{
	ssize_t	readn;
	char	buf[4096];

	readn = read(fd, buf, sizeof(buf));
	while (readn > 0)
	{
		if (!reader_append(r, buf, (size_t)readn))
			return (false);
		readn = read(fd, buf, sizeof(buf));
	}
	return (true);
}

char	*read_all_text(const char *path, ssize_t *out_len)
{
	int			fd;
	t_reader	r;

	reader_init(&r);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!read_loop(fd, &r))
	{
		free(r.mem);
		close(fd);
		return (NULL);
	}
	close(fd);
	if (!r.mem)
		return (ft_strdup(""));
	r.mem[r.len] = '\0';
	if (out_len)
		*out_len = (ssize_t)r.len;
	return (r.mem);
}

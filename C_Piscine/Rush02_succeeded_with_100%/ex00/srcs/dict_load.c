/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namykim <namykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:50:05 by namykim           #+#    #+#             */
/*   Updated: 2025/11/09 22:50:06 by namykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

static bool	handle_line(t_dict *d, const char *txt, size_t ls, size_t re)
{
	t_view	v;
	char	*k;
	char	*vv;

	v.s = txt;
	v.l = ls;
	v.r = re;
	k = NULL;
	vv = NULL;
	if (re >= ls && parse_dict_entry(&v, &k, &vv))
	{
		if (!dict_push(d, k, vv))
			return (free(k), free(vv), false);
		free(k);
		free(vv);
	}
	return (true);
}

static bool	process_lines(t_dict *d, char *txt, ssize_t len)
{
	size_t	i;
	size_t	ls;
	size_t	re;

	i = 0;
	ls = 0;
	while ((ssize_t)i <= len)
	{
		if (txt[i] == '\n' || (ssize_t)i == len)
		{
			if (i > 0)
				re = i - 1;
			else
				re = 0;
			if (!handle_line(d, txt, ls, re))
				return (false);
			ls = i + 1;
		}
		i++;
	}
	return (true);
}

bool	dict_load(t_dict *d, const char *path)
{
	ssize_t	len;
	char	*txt;
	bool	ok;

	txt = read_all_text(path, &len);
	if (!txt)
		return (false);
	ok = process_lines(d, txt, len);
	free(txt);
	return (ok);
}

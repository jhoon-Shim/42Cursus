/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namykim <namykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:54:48 by namykim           #+#    #+#             */
/*   Updated: 2025/11/09 22:54:49 by namykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

bool	normalize_number(const char *in, char **out_norm)
{
	size_t	i;
	size_t	n;

	if (!in || !in[0])
		return (false);
	i = 0;
	while (in[i])
	{
		if (!ft_is_digit(in[i]))
			return (false);
		i++;
	}
	n = i;
	i = 0;
	while (i < n && in[i] == '0')
		i++;
	if (i == n)
		*out_norm = ft_strdup("0");
	else
		*out_norm = ft_strndup(in + i, n - i);
	return (*out_norm != NULL);
}

static bool	is_zero_group(const t_group *g)
{
	if (g->d[0] != '0')
		return (false);
	if (g->d[1] != '0')
		return (false);
	if (g->d[2] != '0')
		return (false);
	return (true);
}

static void	fill_one(t_group *g, const char *num, long *idx)
{
	g->d[0] = '0';
	g->d[1] = '0';
	g->d[2] = '0';
	if (*idx >= 0)
	{
		g->d[2] = num[*idx];
		*idx = *idx - 1;
	}
	if (*idx >= 0)
	{
		g->d[1] = num[*idx];
		*idx = *idx - 1;
	}
	if (*idx >= 0)
	{
		g->d[0] = num[*idx];
		*idx = *idx - 1;
	}
	g->zero = is_zero_group(g);
}

t_group	*split_groups(const char *num, size_t *out_cnt)
{
	size_t	n;
	size_t	cnt;
	long	idx;
	size_t	i;
	t_group	*g;

	n = ft_strlen(num);
	cnt = (n + 2) / 3;
	g = (t_group *)malloc(sizeof(t_group) * cnt);
	if (!g)
		return (NULL);
	idx = (long)n - 1;
	i = 0;
	while (i < cnt)
	{
		fill_one(&g[i], num, &idx);
		i++;
	}
	*out_cnt = cnt;
	return (g);
}

char	*make_scale_str(size_t k)
{
	size_t	z;
	size_t	i;
	char	*s;

	z = 3 * k;
	s = (char *)malloc(z + 2);
	if (!s)
		return (NULL);
	s[0] = '1';
	i = 0;
	while (i < z)
	{
		s[1 + i] = '0';
		i++;
	}
	s[1 + z] = '\0';
	return (s);
}

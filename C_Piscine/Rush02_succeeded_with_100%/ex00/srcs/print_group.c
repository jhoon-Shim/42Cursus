/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <hnoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:00:00 by you               #+#    #+#             */
/*   Updated: 2025/11/08 16:44:16 by hnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

bool		say_two(const t_dict *d, char t, char o, bool *first);

static void	put_tok(const char *t, bool *first)
{
	if (!t || !t[0])
		return ;
	if (!*first)
		put_char(' ');
	put_str(t);
	*first = false;
}

static bool	say_three(const t_dict *d, const t_group *g, bool *first)
{
	char	k[2];
	char	*v;

	if (g->zero)
		return (true);
	if (g->d[0] != '0')
	{
		k[0] = g->d[0];
		k[1] = '\0';
		v = dict_lookup(d, k);
		if (!v)
			return (false);
		put_tok(v, first);
		v = dict_lookup(d, "100");
		if (!v)
			return (false);
		put_tok(v, first);
	}
	return (say_two(d, g->d[1], g->d[2], first));
}

bool	print_group_with_scale(const t_dict *d, const t_group *g,
			size_t idx, bool *first)
{
	char	*sc;
	char	*sv;

	if (!say_three(d, g, first))
		return (false);
	if (!g->zero && idx > 0)
	{
		sc = make_scale_str(idx);
		if (!sc)
			return (false);
		sv = dict_lookup(d, sc);
		if (!sv)
			return (free(sc), false);
		put_tok(sv, first);
		free(sc);
	}
	return (true);
}

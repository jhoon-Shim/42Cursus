/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namykim <namykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:55:06 by namykim           #+#    #+#             */
/*   Updated: 2025/11/09 22:55:07 by namykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

static void	put_tok(const char *t, bool *first)
{
	if (!t || !t[0])
		return ;
	if (!*first)
		put_char(' ');
	put_str(t);
	*first = false;
}

static bool	say_units(const t_dict *d, char o, bool *first)
{
	char	k[2];
	char	*v;

	if (o == '0')
		return (true);
	k[0] = o;
	k[1] = '\0';
	v = dict_lookup(d, k);
	if (!v)
		return (false);
	put_tok(v, first);
	return (true);
}

static bool	say_teens(const t_dict *d, char o, bool *first)
{
	char	k[3];
	char	*v;

	k[0] = '1';
	k[1] = o;
	k[2] = '\0';
	v = dict_lookup(d, k);
	if (!v)
		return (false);
	put_tok(v, first);
	return (true);
}

static bool	say_tens(const t_dict *d, char t, bool *first)
{
	char	k[3];
	char	*v;

	k[0] = t;
	k[1] = '0';
	k[2] = '\0';
	v = dict_lookup(d, k);
	if (!v)
		return (false);
	put_tok(v, first);
	return (true);
}

bool	say_two(const t_dict *d, char t, char o, bool *first)
{
	if (t == '0' && o == '0')
		return (true);
	if (t == '0')
		return (say_units(d, o, first));
	if (t == '1')
		return (say_teens(d, o, first));
	if (!say_tens(d, t, first))
		return (false);
	return (say_units(d, o, first));
}

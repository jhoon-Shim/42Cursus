/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namykim <namykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:50:38 by namykim           #+#    #+#             */
/*   Updated: 2025/11/09 22:50:40 by namykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

static bool	find_key_bounds(t_view *v, size_t *kb, size_t *ke)
{
	*kb = v->l;
	while (*kb <= v->r && ft_is_space(v->s[*kb]))
		(*kb)++;
	*ke = *kb;
	while (*ke <= v->r && ft_is_digit(v->s[*ke]))
		(*ke)++;
	if (*kb == *ke)
		return (false);
	return (true);
}

static bool	find_colon(t_view *v, size_t ke, size_t *c)
{
	*c = ke;
	while (*c <= v->r && ft_is_space(v->s[*c]))
		(*c)++;
	if (*c > v->r || v->s[*c] != ':')
		return (false);
	(*c)++;
	return (true);
}

static bool	extract_value(t_view *v, size_t c, char **ov)
{
	size_t	vb;
	char	*rv;

	vb = c;
	while (vb <= v->r && ft_is_space(v->s[vb]))
		vb++;
	if (vb > v->r)
		return (false);
	rv = ft_strndup(v->s + vb, v->r - vb + 1);
	*ov = ft_strtrim(rv);
	free(rv);
	if (!*ov)
		return (false);
	return (true);
}

bool	parse_dict_entry(t_view *v, char **ok, char **ov)
{
	size_t	kb;
	size_t	ke;
	size_t	c;

	while (v->l <= v->r && ft_is_space(v->s[v->l]))
		v->l++;
	while (v->r > v->l && ft_is_space(v->s[v->r]))
		v->r--;
	if (v->l > v->r)
		return (false);
	if (!find_key_bounds(v, &kb, &ke))
		return (false);
	if (!find_colon(v, ke, &c))
		return (false);
	*ok = ft_strndup(v->s + kb, ke - kb);
	if (!*ok)
		return (false);
	if (!extract_value(v, c, ov))
		return (free_ptr((void **)ok), false);
	return (true);
}

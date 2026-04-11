/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namykim <namykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:56:17 by namykim           #+#    #+#             */
/*   Updated: 2025/11/09 22:56:18 by namykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

static bool	print_zero(const t_dict *d)
{
	char	*z;

	z = dict_lookup(d, "0");
	if (!z)
		return (false);
	put_str(z);
	return (true);
}

static bool	print_all_groups(const t_dict *d, t_group *g, size_t cnt)
{
	size_t	i;
	bool	first;

	first = true;
	i = cnt;
	while (i-- > 0)
	{
		if (!print_group_with_scale(d, &g[i], i, &first))
			return (false);
	}
	return (true);
}

bool	print_number_words(const t_dict *d, const char *num)
{
	size_t	cnt;
	t_group	*groups;

	if (ft_strcmp(num, "0") == 0)
		return (print_zero(d));
	groups = split_groups(num, &cnt);
	if (!groups)
		return (false);
	if (!print_all_groups(d, groups, cnt))
		return (free(groups), false);
	free(groups);
	return (true);
}

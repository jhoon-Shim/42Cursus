/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.campus>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:00:00 by you               #+#    #+#             */
/*   Updated: 2025/11/08 15:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	dict_init(t_dict *d)
{
	d->arr = NULL;
	d->size = 0;
	d->cap = 0;
	return (true);
}

void	dict_free(t_dict *d)
{
	size_t	i;

	if (!d)
		return ;
	i = 0;
	while (i < d->size)
	{
		free(d->arr[i].key);
		free(d->arr[i].val);
		i++;
	}
	free(d->arr);
	d->arr = NULL;
	d->size = 0;
	d->cap = 0;
}

static bool	dict_grow(t_dict *d)
{
	size_t			i;
	size_t			ncap;
	t_dict_entry	*tmp;

	if (d->cap == 0)
		ncap = 64;
	else
		ncap = d->cap * 2;
	tmp = (t_dict_entry *)malloc(ncap * sizeof(*tmp));
	if (!tmp)
		return (false);
	i = 0;
	while (i < d->size)
	{
		tmp[i] = d->arr[i];
		i++;
	}
	free(d->arr);
	d->arr = tmp;
	d->cap = ncap;
	return (true);
}

bool	dict_push(t_dict *d, const char *k, const char *v)
{
	if (d->size + 1 > d->cap)
		if (!dict_grow(d))
			return (false);
	d->arr[d->size].key = ft_strdup(k);
	d->arr[d->size].val = ft_strdup(v);
	if (!d->arr[d->size].key || !d->arr[d->size].val)
		return (false);
	d->size++;
	return (true);
}

char	*dict_lookup(const t_dict *d, const char *key)
{
	size_t	i;

	i = 0;
	while (i < d->size)
	{
		if (ft_strcmp(d->arr[i].key, key) == 0)
			return (d->arr[i].val);
		i++;
	}
	return (NULL);
}

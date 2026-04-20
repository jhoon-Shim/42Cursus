/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:03:01 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 12:00:08 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char				*tmp;
	size_t				i;

	i = 0;
	tmp = (char *) malloc (ft_strlen(s) + 1);
	if (!tmp)
		return (NULL);
	while (i < ft_strlen(s))
	{
		tmp[i] = s[i];
		i ++;
	}
	tmp[i] = '\0';
	return (tmp);
}

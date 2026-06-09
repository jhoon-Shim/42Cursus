/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:12:39 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 13:57:50 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bigs, const char *littles, size_t n)
{
	size_t	i;
	size_t	j;

	if (*littles == '\0')
		return ((char *)bigs);
	i = 0;
	while (i < n && bigs[i] != '\0')
	{
		j = 0;
		while (i + j < n && littles[j] != '\0' && bigs[i + j] == littles[j])
			j ++;
		if (littles[j] == '\0')
			return ((char *)(bigs + i));
		i ++;
	}
	return (NULL);
}

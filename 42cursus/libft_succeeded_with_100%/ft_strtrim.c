/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:20:04 by jshim             #+#    #+#             */
/*   Updated: 2026/01/25 13:58:56 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start ++;
		while (end > start && s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end --;
		str = (char *) malloc (end - start + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s1[start], end - start + 1);
	}
	return (str);
}

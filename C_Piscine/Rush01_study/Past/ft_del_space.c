/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:11:36 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 16:45:57 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

char	*ft_del_space(char *str)
{
	int		i;
	int		len;
	char	*tmp;
	int		j;

	len = ft_strlen(str);
	tmp = (char *)malloc((len + 1) * 1);
	if (tmp == NULL)
	{
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] != ' ')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	return (tmp);
}

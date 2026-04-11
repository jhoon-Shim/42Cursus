/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:55:13 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 16:48:56 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	isvalid_view(char *str)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != ' ')
			cnt++;
		if (str[i] <= 0 || str[i] >= 5)
			return (-1);
		i++;
	}
	return (cnt);
}

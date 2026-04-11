/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:24:57 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 19:00:17 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	if (*str >= '1' && *str <= '9')
		res = *str - '0';
	return (res);
}

int	check_format(char *str, int *i, int total_clues)
{
	if (*str == '\0' || !(*str >= '1' && *str <= '9'))
		return (0);
	if (*i < total_clues - 1)
	{
		if (*(str + 1) != ' ')
			return (0);
	}
	else if (*(str + 1) != '\0')
		return (0);
	return (1);
}

int	parse_clues(char *str, int *clues, int size)
{
	int	i;
	int	total_clues;

	i = 0;
	total_clues = size * 4;
	if (!str || !clues || total_clues < 16)
		return (0);
	while (i < total_clues)
	{
		if (!check_format(str, &i, total_clues))
			return (0);
		clues[i] = ft_atoi(str);
		str++;
		if (i < total_clues - 1)
			str++;
		i++;
	}
	return (1);
}

void	print_grid(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->size)
	{
		j = 0;
		while (j < game->size)
		{
			c = game->grid[i][j] + '0';
			write(1, &c, 1);
			if (j < game->size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

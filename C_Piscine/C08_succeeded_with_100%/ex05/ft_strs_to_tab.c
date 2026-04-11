/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:27:24 by jshim             #+#    #+#             */
/*   Updated: 2025/11/06 22:14:58 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dup;

	len = ft_strlen(src);
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (!tab[i].copy)
		{
			while (i > 0)
				free(tab[--i].copy);
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i].str = 0;
	tab[i].size = 0;
	tab[i].copy = 0;
	return (tab);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char			*words[] = {"Hello", "42Seoul", "Piscine", "C08", NULL};
// 	t_stock_str		*tab;
// 	int				i;

// 	tab = ft_strs_to_tab(4, words);
// 	if (!tab)
// 	{
// 		printf("Memory allocation failed.\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (tab[i].str)
// 	{
// 		printf("Word %d:\n", i);
// 		printf("  size: %d\n", tab[i].size);
// 		printf("  str : %s\n", tab[i].str);
// 		printf("  copy: %s\n\n", tab[i].copy);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 4)
// 		free(tab[i++].copy);
// 	free(tab);
// 	return (0);
// }
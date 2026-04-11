/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 00:36:52 by jshim             #+#    #+#             */
/*   Updated: 2025/11/13 01:17:19 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = 0;
	while (tab[i])
	{
		j = i;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = tmp;
			}
			j++;
		}
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *str1[] = {"Cmes", "Bello", "A'm", "Apple", "App", NULL};
// 	ft_sort_string_tab(str1);
// 	for (int i = 0; i<5 ;i++)
// 		printf("%s\n",str1[i]);
// }
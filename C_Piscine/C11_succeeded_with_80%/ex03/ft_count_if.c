/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:00:21 by jshim             #+#    #+#             */
/*   Updated: 2025/11/12 21:04:32 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			cnt ++;
		i++;
	}
	return (cnt);
}

// #include <stdio.h>

// int is_nonempty(char *str)
// {
// 	return (str[0] != '\0');
// }

// int main(void)
// {
// 	char *arr[] = {"hello", "", "42", "world", ""};
// 	int len = 5;

// 	printf("%d\n", ft_count_if(arr, len, &is_nonempty));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:16:31 by jshim             #+#    #+#             */
/*   Updated: 2025/11/13 01:30:57 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (i < ft_strlen(tab))
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	is_non_empty(char *str)
// {
// 	return (str[0] != '\0'); // 문자열이 비어있지 않으면 1 반환
// }

// int	ft_any(char **tab, int (*f)(char*));

// int	main(void)
// {
// 	char *arr1[] = {"", "", "Hello", NULL};
// 	char *arr2[] = {"", "", "", NULL};

// 	printf("%d\n", ft_strlen(arr1));
// 	printf("%d\n", ft_any(arr1, &is_non_empty)); // 1 (Hello가 true)
// 	printf("%d\n", ft_any(arr2, &is_non_empty)); // 0 (모두 false)
// }

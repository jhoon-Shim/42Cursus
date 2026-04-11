/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:18:08 by jshim             #+#    #+#             */
/*   Updated: 2025/10/25 17:20:40 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <stdlib.h>
*/

char	*ft_strlowcase(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx) != '\0')
	{
		if (*(str + idx) >= 'A' && *(str + idx) <= 'Z')
		{
			*(str + idx) = *(str + idx) + 'a' - 'A';
		}
		idx ++;
	}
	return (str);
}

/*
int main(void)
{
	char *test;
	char test1[100];
	int i;

	for (i = 0 ; i<50; i++)
	{
		test1[i] = 32 + rand() % 90;
	}
	test1[i] = '\0';

	test = test1;
	printf("test = %s\n", test);
	ft_strlowcase(test);
	printf("--> test = %s\n", test);
	return 0;
}
*/
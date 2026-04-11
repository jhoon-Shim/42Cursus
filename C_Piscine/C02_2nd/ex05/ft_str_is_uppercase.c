/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:49:47 by jshim             #+#    #+#             */
/*   Updated: 2025/10/24 23:54:33 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int	ft_str_is_uppercase(char *str)
{
	int	idx;
	int	flag;

	idx = 0;
	flag = 1;
	while (str[idx] != '\0')
	{
		if (str[idx] < 'A' || str[idx] > 'Z')
		{
			flag = 0;
		}
		idx ++;
	}
	return (flag);
}

/*
int	main(void)
{
	char *test1;
	char *test2;
	char *test3;

	test1 = "SFNHKLSADJLKSA";
	test2 = "asASDASDkasldAAA";
	test3 = "";

	printf("%d %d %d\n", 
	ft_str_is_uppercase(test1),
	ft_str_is_uppercase(test2), 
	ft_str_is_uppercase(test3));
	return 0;
}
*/
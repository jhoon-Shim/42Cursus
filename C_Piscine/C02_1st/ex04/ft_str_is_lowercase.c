/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:47:30 by jshim             #+#    #+#             */
/*   Updated: 2025/10/24 23:54:57 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int	ft_str_is_lowercase(char *str)
{
	int	idx;
	int	flag;

	idx = 0;
	flag = 1;
	while (str[idx] != '\0')
	{
		if (str[idx] < 'a')
		{
			flag = 0;
		}
		else if (str[idx] > 'z')
		{
			flag = 0;
		}
		idx ++;
	}
	return (flag);
}

/*
int main()
{
	char *test1;
	char *test2;
	char *test3;

	test1 = "saldjalskdjsad";
	test2 = "asjdlkasldAAA";
	test3 = "";

	printf("%d %d %d\n", 
	ft_str_is_lowercase(test1),
	ft_str_is_lowercase(test2), 
	ft_str_is_lowercase(test3));
	return 0;
}
*/
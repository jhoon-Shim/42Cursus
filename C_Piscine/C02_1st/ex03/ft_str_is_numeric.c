/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:43:47 by jshim             #+#    #+#             */
/*   Updated: 2025/10/24 23:46:51 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int	ft_str_is_numeric(char *str)
{
	int	idx;
	int	flag;

	idx = 0;
	flag = 1;
	while (str[idx] != '\0')
	{
		if (str[idx] < '0')
		{
			flag = 0;
		}
		else if (str[idx] > '9')
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

	test1 = "13245678901203802193";
	test2 = "asjdlkasld213678124AAA";
	test3 = "";

	printf("%d %d %d\n", 
	ft_str_is_numeric(test1),
	ft_str_is_numeric(test2), 
	ft_str_is_numeric(test3));
	return 0;
}
*/
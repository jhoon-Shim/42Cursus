/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:39:53 by jshim             #+#    #+#             */
/*   Updated: 2025/10/24 23:29:01 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int	ft_str_is_alpha(char *str)
{
	int	idx;
	int	flag;

	idx = 0;
	flag = 1;
	while (str[idx] != '\0')
	{
		if (str[idx] < 'A')
		{
			flag = 0;
		}
		else if (str[idx] > 'Z' && str[idx] < 'a')
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

	test1 = "saldjalskdjASHASLKDJKLAS";
	test2 = "asjdlkasld[]_AAA";
	test3 = "";

	printf("%d %d %d\n", 
	ft_str_is_alpha(test1),
	ft_str_is_alpha(test2), 
	ft_str_is_alpha(test3));
	return 0;
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:56:29 by jshim             #+#    #+#             */
/*   Updated: 2025/10/25 14:00:28 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int	ft_str_is_printable(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] < 32 || str[idx] > 126)
		{
			return (0);
		}
		idx ++;
	}
	return (1);
}

/*
int	main(void)
{
	char *test1;
	char *test2;
	char *test3;

	test1 = "€";
	test2 = "UNIT SEPARATOR (US) DOWN ARROW";
	test3 = " ";

	printf("%d %d %d\n", 
	ft_str_is_printable(test1),
	ft_str_is_printable(test2), 
	ft_str_is_printable(test3));
	return 0;
}
*/
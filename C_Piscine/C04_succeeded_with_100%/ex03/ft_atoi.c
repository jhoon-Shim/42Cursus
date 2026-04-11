/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:29:04 by jshim             #+#    #+#             */
/*   Updated: 2025/10/30 16:56:44 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx) == ' '
		|| *(str + idx) == '\n'
		|| *(str + idx) == '\t'
		|| *(str + idx) == '\v'
		|| *(str + idx) == '\f'
		|| *(str + idx) == '\r')
		idx ++;
	return (idx);
}

void	ft_sign(char *str, int *result)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	result[0] = i;
	result[1] = sign;
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	idxnsign[2];

	i = ft_isspace(str);
	ft_sign(str + i, idxnsign);
	i += idxnsign[0];
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= idxnsign[1];
	return (num);
}

// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	if (argc > 1)
// 	{
// 		printf("%d\n", ft_atoi(*(argv + 1)));
// 		printf("%s\n", argv[1]);
// 	}
// 	return (0);
// }

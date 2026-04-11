/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:05:25 by jshim             #+#    #+#             */
/*   Updated: 2025/11/05 22:15:13 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
		i++;
	if (i < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_isspace(char *str)
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

static void	ft_sign(char *str, int *result)
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

static int	ft_index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	num;
	int	idxnsign[2];
	int	val;
	int	j;

	if (!check_base(base))
		return (0);
	i = ft_isspace(str);
	ft_sign(str + i, idxnsign);
	i += idxnsign[0];
	num = 0;
	j = 0 ;
	while (base[j])
		j++;
	while (ft_index_in_base(str[i], base) != -1)
	{
		val = ft_index_in_base(str[i], base);
		num = num * j + val;
		i++;
	}
	return (num *= idxnsign[1]);
}

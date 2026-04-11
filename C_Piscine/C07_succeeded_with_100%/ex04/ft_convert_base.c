/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:05:23 by jshim             #+#    #+#             */
/*   Updated: 2025/11/05 22:36:58 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);
int		ft_atoi_base(char *str, char *base);

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_get_nbr_len(long nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

static void	ft_fill_result(long nbr, char *base, char *result, int len)
{
	int	base_len;

	base_len = ft_strlen(base);
	result[len] = '\0';
	len--;
	if (nbr == 0)
	{
		result[len] = base[0];
		return ;
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		result[len] = base[nbr % base_len];
		nbr /= base_len;
		len--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num_decimal;
	long	long_num;
	char	*result;
	int		result_len;
	int		base_to_len;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	base_to_len = ft_strlen(base_to);
	num_decimal = ft_atoi_base(nbr, base_from);
	long_num = (long)num_decimal;
	result_len = ft_get_nbr_len(long_num, base_to_len);
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (!result)
		return (NULL);
	ft_fill_result(long_num, base_to, result, result_len);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:42:20 by jshim             #+#    #+#             */
/*   Updated: 2025/11/09 14:54:09 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* utils.c */

#include "bsq.h"

/* 에러 메시지 출력 (표준 에러) */
void	ft_putstr_err(char *str)
{
	write(2, str, ft_strlen(str));
}

/* 문자열 출력 (표준 출력) */
void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/* 문자열 길이 계산 */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/* 문자열을 정수로 변환 (첫 N개 문자만) */
int	ft_atoi(char *str, int len)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (i < len && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

/* 세 정수 중 최솟값 반환 (DP 알고리즘의 핵심) */
int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}
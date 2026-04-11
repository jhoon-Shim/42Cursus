/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:51:49 by jshim             #+#    #+#             */
/*   Updated: 2025/10/26 11:07:07 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h> 

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*(str + length) != '\0')
	{
		length++;
	}
	return (length);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (idx < size -1 && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx ++;
	}
	dest[idx] = '\0';
	return (ft_strlen(src));
}

// int main ()
// {
// 	char ch[20];
// 	char *src = "2178321jhska";
// 	int num;

// 	num = ft_strlcpy(ch,src,2);

// 	printf("%s %d\n", ch, num);
// }

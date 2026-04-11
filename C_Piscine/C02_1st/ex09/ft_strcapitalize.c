/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:21:19 by jshim             #+#    #+#             */
/*   Updated: 2025/10/26 10:59:04 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h> 

char	*ft_strcapitalize(char *str)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (str[idx] != '\0')
	{
		while ((str[idx + count] >= 'a' && str[idx + count] <= 'z')
			|| (str [idx + count] >= '0' && str[idx + count] <= '9'))
		{
			count ++;
		}
		if (str[idx] >= 'a' && str[idx] <= 'z')
		{
			str[idx] -= 'a' - 'A';
		}
		idx += count + 1;
		count = 0;
	}
	return (str);
}

// int main(void)
// {
// 	char *str;
// 	char arr[] = "hi, how are you? h 42words forty-two; fifty+and+one";
// 	str = arr;
// 	ft_strcapitalize(str);
// 	printf("%s\n",str);
// 	return (0);
// }

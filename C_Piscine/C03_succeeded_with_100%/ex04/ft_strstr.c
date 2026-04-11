/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:12:46 by jshim             #+#    #+#             */
/*   Updated: 2025/10/28 02:47:04 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char ch[100] = "asdljasdkljabcqwewqe";
// 	char tofind[100] = "12";
// 	char *test;

// 	test = ft_strstr(ch,tofind);

// 	printf("%s\n",test);
// } 
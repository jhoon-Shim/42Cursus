/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:21:19 by jshim             #+#    #+#             */
/*   Updated: 2025/10/26 15:46:07 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0)
			|| !((str[i - 1] >= 'a' && str[i - 1] <= 'z')
				|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - ('a' - 'A');
		}
		i++;
	}
	return (str);
}

// int main(void)
// {
// 	char *str;
// 	char arr[] = "AWEHIASDJska wjqeiASDQE';llk 2 forty-two; fifty+and+one";
// 	str = arr;
// 	ft_strcapitalize(str);
// 	printf("%s\n",str);
// 	return (0);
// }

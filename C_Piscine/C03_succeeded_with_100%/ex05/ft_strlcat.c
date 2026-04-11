/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:41:24 by jshim             #+#    #+#             */
/*   Updated: 2025/10/28 02:47:03 by jshim            ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	while (src[j] && (i + j + 1 < size))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	if (dest_len < size)
	{
		return (src_len + dest_len);
	}
	else
	{
		return (src_len + size);
	}
}

// #include <stdio.h>

// int main(void)
// {
// 	char s1[100] = "asdnbjkans";
// 	char s2[100] = "4655464315";
// 	int num = 0;
// 	printf("%s\n%s\n", s1, s2);
// 	num = ft_strlcat(s1,s2,12);
// 	printf("%s\n%s\n %d",s1,s2, num);
// 	return (0);
// }
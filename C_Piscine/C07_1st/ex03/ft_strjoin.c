/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:14:02 by jshim             #+#    #+#             */
/*   Updated: 2025/11/06 11:38:52 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	length_join(int size, char **strs, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (size == 0)
		return (1);
	while (i < size)
	{
		count += ft_strlen(strs[i]);
		i++;
	}
	count += ft_strlen(sep) * (size - 1);
	return (++count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		len_join;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	len_join = length_join(size, strs, sep);
	joined = (char *) malloc (sizeof(char) * len_join);
	if (joined == NULL)
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (j < ft_strlen(strs[i]))
			joined[k++] = strs[i][j++];
		j = 0;
		while (i < size -1 && j < ft_strlen(sep))
			joined[k++] = sep[j++];
		i++;
	}
	joined[k] = '\0';
	return (joined);
}

// #include <stdio.h>

// int main()
// {
// 	char *str[] = {"Hello","I'm","john","Hi","Thanks"};
// 	char sep[] = "sep";
// 	int size = 5;
// 	char *joined;

// 	joined = ft_strjoin(size,str,sep);
// 	printf("%s\n",joined);
// }
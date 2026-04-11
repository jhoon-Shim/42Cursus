/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:38:09 by jshim             #+#    #+#             */
/*   Updated: 2025/11/06 11:39:01 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_separator(*str, charset))
		{
			in_word = 0;
		}
		else
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		str++;
	}
	return (count);
}

static char	*create_word(char *src, int len)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		word_count;
	int		i;
	char	*word_start;

	word_count = count_words(str, charset);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*str && is_separator(*str, charset))
			str++;
		word_start = str;
		while (*str && !is_separator(*str, charset))
			str++;
		split[i] = create_word(word_start, str - word_start);
		if (!split[i])
			return (NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*charset;
// 	char	**result;
// 	int		i;

// 	str = "Hello,,World! This is.a,test.";
// 	charset = ",.! ";

// 	printf("Original string: \"%s\"\n", str);
// 	printf("Charset: \"%s\"\n", charset);

// 	result = ft_split(str, charset);

// 	if (!result)
// 	{
// 		printf("Memory allocation failed or empty result.\n");
// 		return (1);
// 	}

// 	printf("Split result:\n");
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("result[%d]: \"%s\"\n", i, result[i]);
// 		i++;
// 	}

// 	printf("\n--- Test Case 2 ---\n");
// 	str = "   split   this   string   ";
// 	charset = "a";

// 	result = ft_split(str, charset);

// 	printf("Original string: \"%s\"\n", str);
// 	printf("Split result:\n");
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("result[%d]: \"%s\"\n", i, result[i]);
// 		i++;
// 	}

// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:10:54 by jshim             #+#    #+#             */
/*   Updated: 2026/06/05 12:09:12 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static int	count_words(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			count++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	word_len(const char *str, char charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_charset(str[len], charset))
		len++;
	return (len);
}

static char	*ft_strdup_word(const char *str, char charset,
			char **result, int filled)
{
	char	*word;
	int		len;
	int		i;

	len = word_len(str, charset);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		i = 0;
		while (i < filled)
			free(result[i++]);
		free(result);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_charset(s[i], c))
			i++;
		if (!s[i])
			break ;
		result[j] = ft_strdup_word(&s[i], c, result, j);
		if (!result[j])
			return (NULL);
		j++;
		i += word_len(&s[i], c);
	}
	result[j] = NULL;
	return (result);
}

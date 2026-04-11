/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namykim <namykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:48:44 by namykim           #+#    #+#             */
/*   Updated: 2025/11/09 22:48:48 by namykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>

/* dictionary */
typedef struct s_dict_entry
{
	char			*key;
	char			*val;
}	t_dict_entry;

typedef struct s_dict
{
	t_dict_entry	*arr;
	size_t			size;
	size_t			cap;
}	t_dict;

/* shared structs moved to header (no typedefs in .c) */
typedef struct s_view
{
	const char	*s;
	size_t		l;
	size_t		r;
}	t_view;

typedef struct s_reader
{
	char		*mem;
	size_t		len;
	size_t		cap;
}	t_reader;

/* str.c / str_more.c */
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *a, const char *b);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
bool	ft_is_space(char c);
bool	ft_is_digit(char c);
char	*ft_strtrim(const char *s);

/* utils.c */
void	put_char(char c);
void	put_str(const char *s);
void	put_err(const char *s);
void	free_ptr(void **p);

/* fileio.c */
char	*read_all_text(const char *path, ssize_t *out_len);

/* dict.c / dict_load.c */
bool	dict_init(t_dict *d);
void	dict_free(t_dict *d);
bool	dict_push(t_dict *d, const char *k, const char *v);
char	*dict_lookup(const t_dict *d, const char *key);
bool	dict_load(t_dict *d, const char *path);

/* dict_parse.c */
bool	parse_dict_entry(t_view *v, char **ok, char **ov);

/* num.c */
bool	normalize_number(const char *in, char **out_norm);

typedef struct s_group
{
	char			d[3];
	bool			zero;
}	t_group;

t_group	*split_groups(const char *num, size_t *out_cnt);
char	*make_scale_str(size_t k);

/* print */
bool	print_number_words(const t_dict *d, const char *num);
bool	print_group_with_scale(const t_dict *d, const t_group *g,
			size_t idx, bool *first);

#endif

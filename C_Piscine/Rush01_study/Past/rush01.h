/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:55:21 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 17:00:33 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

int		**allocate_view(int rows, int cols);

void	parse_input_views(int **col_view, int **row_view, char *tmp, int n);

void	free_view(int **view, int rows);

int		error_msg(void);

char	*ft_del_space(char *str);

int		is_valid_view(char *str);

int		ft_strlen(char *str);

#endif
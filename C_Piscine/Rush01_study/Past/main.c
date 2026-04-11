/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:30:21 by jshim             #+#    #+#             */
/*   Updated: 2025/11/01 17:57:02 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char *argv[])
{
	int	**col_view;
	int	**row_view;
	char	*tmp;
	int	n;
	int	rows_n;
	int	cols_n;
	int	flag; 
	
	flag = 0;
	if (argc <= 1)
		return (0);
	flag = isvalid_view(argv[1]);
	if (flag== -1)
		return (error_msg());
	if (flag % 4 != 0)
		return (error_msg());
	if (flag >= 37)
		return (error_msg());
	if (flag == 0)
		return (error_msg());
	rows_n = flag / 4;
	cols_n = flag / 4;
	col_view = allocate_view(rows_n, cols_n);
	if (col_view == NULL)
		return (error_msg());
	row_view = allocate_view(rows_n, cols_n);
	if (row_view == NULL)
	{
		free_view(col_view, rows_n);
		return (error_msg());
	}

	tmp = ft_del_space(argv[1]);
	if (tmp == NULL)
	{
		free_view(col_view, rows_n);
		free_view(row_view, rows_n);
		return (error_msg());
	}
	parse_input_views(col_view, row_view, tmp, n);

	free_view(col_view, rows_n);
	free_view(row_view, rows_n);
	free(tmp);
	return (0);
}
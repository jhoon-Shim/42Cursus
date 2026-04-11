/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:13:54 by jshim             #+#    #+#             */
/*   Updated: 2025/11/06 22:14:14 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);

int main(void)
{
    char *words[] = {"Hello", "42Seoul", "Piscine", "C08"};
    int size = 4;


    t_stock_str *tab = ft_strs_to_tab(size, words);
    if (!tab)
        return (1); 

    ft_show_tab(tab);

    for (int i = 0; i < size; i++)
        free(tab[i].copy);
    free(tab);

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:25:53 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 04:38:15 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

// // main.c
// #include <stdio.h>

// static void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("[%s] -> ", (char *)lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }

// int main(void)
// {
//     t_list n1 = {"A", NULL};
//     t_list n2 = {"B", NULL};
//     t_list n3 = {"C", NULL};
//     t_list *lst = NULL;

//     /* NORMAL */
//     ft_lstadd_front(&lst, &n1);
//     ft_lstadd_front(&lst, &n2);
//     ft_lstadd_front(&lst, &n3);
//     printf("[NORMAL]   ");
//     print_list(lst);

//     /* EDGE */
//     t_list *empty = NULL;
//     ft_lstadd_front(&empty, &n1);
//     printf("[EDGE]     ");
//     print_list(empty);

//     /* OVERFLOW */
//     ft_lstadd_front(&lst, NULL);
//     printf("[OVERFLOW] new == NULL ignored\n");

//     return 0;
// }

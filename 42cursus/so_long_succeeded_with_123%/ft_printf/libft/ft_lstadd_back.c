/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 01:09:10 by jshim             #+#    #+#             */
/*   Updated: 2026/01/24 04:44:37 by jshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
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
//     ft_lstadd_back(&lst, &n1);
//     ft_lstadd_back(&lst, &n2);
//     ft_lstadd_back(&lst, &n3);
//     printf("[NORMAL]   ");
//     print_list(lst);

//     /* EDGE */
// 	n1.next = NULL;
// 	n2.next = NULL;
// 	n3.next = NULL;

// 	t_list *empty = NULL;
// 	ft_lstadd_back(&empty, &n1);

// 	printf("[EDGE]     ");
// 	print_list(empty);

//     /* OVERFLOW */
//     ft_lstadd_back(&lst, NULL);
//     printf("[OVERFLOW] new == NULL ignored\n");

//     return 0;
// }

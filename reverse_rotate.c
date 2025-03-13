/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:58:29 by makamins          #+#    #+#             */
/*   Updated: 2025/03/12 18:19:41 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **list)
{
    t_list 	*node_to_reverse;

	if (!*list || !(*list)->next)
		return ;
	node_to_reverse = find_last(*list);
	if (node_to_reverse->prev)
		node_to_reverse->prev->next = NULL;
	node_to_reverse->prev = NULL;
	node_to_reverse->next = *list;
	(*list)->prev = node_to_reverse;
	*list = node_to_reverse;
}

void	rra(t_list **list_a)
{
	reverse_rotate(list_a);
	ft_printf("rra\n");
}

void	rrb(t_list **list_b)
{
	reverse_rotate(list_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **list_a, t_list **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:51:21 by makamins          #+#    #+#             */
/*   Updated: 2025/03/19 19:11:03 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **list)
{
	t_list	*node_to_rotate;
	t_list	*last_node;

	if (!*list || !(*list)->next)
		return ;
	node_to_rotate = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->prev = NULL;
	last_node = find_last(*list);
	if (!last_node)
	{
		*list = node_to_rotate;
		node_to_rotate->next = NULL;
	}
	else
	{
		last_node->next = node_to_rotate;
		node_to_rotate->prev = last_node;
		node_to_rotate->next = NULL;
	}
}

void	ra(t_list **list_a)
{
	rotate(list_a);
	ft_printf("ra\n");
}

void	rb(t_list **list_b)
{
	rotate(list_b);
	ft_printf("rb\n");
}

void	rr(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}
//as que vão printar vão ser todas só void
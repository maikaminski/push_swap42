/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:51:39 by makamins          #+#    #+#             */
/*   Updated: 2025/03/27 15:06:35 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **list_dest, t_list **list_src)
{
	t_list	*node_to_push;

	if (!*list_src || !list_src || !list_dest)
		return ;
	node_to_push = *list_src;
	*list_src = (*list_src)->next;
	if (*list_src)
		(*list_src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*list_dest)
	{
		*list_dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *list_dest;
		node_to_push->next->prev = node_to_push;
		*list_dest = node_to_push;
	}
}

void	pa(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	ft_printf("pa\n");
}

void	pb(t_list **list_b, t_list **list_a)
{
	push(list_b, list_a);
	ft_printf("pb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:51:39 by makamins          #+#    #+#             */
/*   Updated: 2025/03/17 13:05:45 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **list_dest, t_list **list_src)
{
    t_list	*node_to_push;

	if (!*list_src)
		return ;
	node_to_push = *list_src; // Remove o primeiro nó da lista de origem
	*list_src = (*list_src)->next;// Remove o primeiro nó da lista de origem
	if (*list_src) // Atualiza o ponteiro prev do novo primeiro nó da lista de origem (se existir)
		(*list_src)->prev = NULL; // Atualiza o ponteiro prev do novo primeiro nó da lista de origem (se existir)
	node_to_push->prev = NULL; // Prepara o nó para ser inserido na lista de destino
	if (!*list_dest)   // Insere o nó na lista de destino
	{
		*list_dest = node_to_push; //se tiver vazia
		node_to_push->next = NULL;
	}
	else
	{ //se já tiver outro node
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

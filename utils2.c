/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:26:41 by makamins          #+#    #+#             */
/*   Updated: 2025/03/20 13:50:09 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position(t_list *list)
{
	int	middle;
	int	i;

	i = 0;
	if (!list)
		return ;
	middle = list_len(list) / 2;
	while (list)
	{
		list->index = i;
		if (i <= middle)
			list->above_median = true;
		else
			list->above_median = false;
		list = list->next;
		i++;
	}
}

t_list *find_cheapest(t_list *list_b)
{
    t_list *cheapest_node;
    long cheapest_cost;

    if (!list_b)
        return (NULL);
    cheapest_cost = LONG_MAX;
    while (list_b)
    {
        if (list_b->push_cost < cheapest_cost)
        {
            cheapest_cost = list_b->push_cost;
            cheapest_node = list_b;
        }
        list_b = list_b->next;
    }
    return (cheapest_node);
}

void move_cheapest_to_a(t_list **list_a, t_list **list_b)
{
    t_list *cheapest_node;

    // Passo 1: Encontrar o nó mais barato em list_b
    cheapest_node = find_cheapest(*list_b);

    // Passo 2: Rotacionar ambas as pilhas, se necessário
    if (cheapest_node->above_median && cheapest_node->target->above_median)
    {
        while (*list_b != cheapest_node && *list_a != cheapest_node->target)
            rr(list_a, list_b);
    }
    else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
    {
        while (*list_b != cheapest_node && *list_a != cheapest_node->target)
            rrr(list_a, list_b);
    }

    // Passo 3: Rotacionar list_b até o nó mais barato estar no topo
    while (*list_b != cheapest_node)
    {
        if (cheapest_node->above_median)
            rb(list_b);
        else
            rrb(list_b);
    }

    // Passo 4: Rotacionar list_a até o target estar no topo
    while (*list_a != cheapest_node->target)
    {
        if (cheapest_node->target->above_median)
            ra(list_a);
        else
            rra(list_a);
    }

    // Passo 5: Mover o nó mais barato de list_b para list_a
    pa(list_a, list_b);
}

void	finalize_sort(t_list **list_a)
{
	t_list	*min_node;

	if (!list_a || !*list_a)
		return ;
	min_node = find_min(*list_a);
	while (*list_a != min_node)
	{
		if (min_node->above_median)
		{
			ra(list_a);
			
		}
		else
			rra(list_a);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:26:41 by makamins          #+#    #+#             */
/*   Updated: 2025/03/27 15:13:36 by makamins         ###   ########.fr       */
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

t_list	*find_cheapest(t_list *list_b)
{
	t_list	*cheapest_node;
	long	cheapest_cost;

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

void	move_cheapest_to_a(t_list **list_a, t_list **list_b)
{
	t_list	*cheap_node;

	cheap_node = find_cheapest(*list_b);
	if (cheap_node->above_median && cheap_node->target->above_median)
		while (*list_b != cheap_node && *list_a != cheap_node->target)
			rr(list_a, list_b);
	else if (!(cheap_node->above_median) && !(cheap_node->target->above_median))
		while (*list_b != cheap_node && *list_a != cheap_node->target)
			rrr(list_a, list_b);
	while (*list_b != cheap_node)
	{
		if (cheap_node->above_median)
			rb(list_b);
		else
			rrb(list_b);
	}
	while (*list_a != cheap_node->target)
	{
		if (cheap_node->target->above_median)
			ra(list_a);
		else
			rra(list_a);
	}
	pa(list_a, list_b);
}

void	move_cheapest_to_b(t_list **list_a, t_list **list_b)
{
	t_list	*cheap_node;

	cheap_node = find_cheapest(*list_a);
	if (cheap_node->above_median && cheap_node->target->above_median)
		while (*list_b != cheap_node->target && *list_a != cheap_node)
			rr(list_a, list_b);
	else if (!(cheap_node->above_median) && !(cheap_node->target->above_median))
		while (*list_b != cheap_node->target && *list_a != cheap_node)
			rrr(list_a, list_b);
	while (*list_a != cheap_node)
	{
		if (cheap_node->above_median)
			ra(list_a);
		else
			rra(list_a);
	}
	while (*list_b != cheap_node->target)
	{
		if (cheap_node->target->above_median)
			rb(list_b);
		else
			rrb(list_b);
	}
	pb(list_b, list_a);
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
			ra(list_a);
		else
			rra(list_a);
	}
}

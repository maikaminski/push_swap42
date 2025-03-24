/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_list_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:53:05 by makamins          #+#    #+#             */
/*   Updated: 2025/03/24 13:39:01 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_closest_smaller(t_list *list_b, int value)
{
	t_list	*node_b;
	t_list	*target;
	long	min_diff;
	long	diff;

	node_b = list_b;
	target = NULL;
	min_diff = LONG_MAX;
	while (node_b)
	{
		diff = value - node_b->value;
		if (node_b->value < value)
		{
			if (diff < min_diff)
			{
				min_diff = diff;
				target = node_b;
			}
		}
		node_b = node_b->next;
	}
	return (target);
}

void	set_target_a(t_list *list_a, t_list *list_b)
{
	t_list	*node_a;
	t_list	*target;

	node_a = list_a;
	while (node_a)
	{
		target = find_closest_smaller(list_b, node_a->value);
		if (!target)
			target = find_max(list_b);
		node_a->target = target;
		node_a = node_a->next;
	}
}

static void	set_cost(t_list *list_a, t_list *list_b)
{
	int	len_a;
	int	len_b;

	len_a = list_len(list_a);
	len_b = list_len(list_b);
	while (list_a)
	{
		list_a->push_cost = list_a->index;
		if (!(list_a->above_median))
			list_a->push_cost = len_a - (list_a->index);
		if (list_a->target)
		{
			if (list_a->target->above_median)
				list_a->push_cost += list_a->target->index;
			else
				list_a->push_cost += len_b - (list_a->target->index);
		}
		list_a = list_a->next;
	}
}

void	prepare_list_a(t_list *list_a, t_list *list_b)
{
	position(list_a);
	position(list_b);
	set_target_a(list_a, list_b);
	set_cost(list_a, list_b);
}

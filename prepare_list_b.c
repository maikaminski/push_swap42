/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_list_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:53:09 by makamins          #+#    #+#             */
/*   Updated: 2025/03/27 14:53:53 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_list *list_a, t_list *list_b)
{
	t_list	*a;
	t_list	*target;
	long	largest;

	while (list_b)
	{
		largest = LONG_MAX;
		a = list_a;
		while (a)
		{
			if (a->value > list_b->value && a->value < largest)
			{
				largest = a->value;
				target = a;
			}
			a = a->next;
		}
		if (largest == LONG_MAX)
			list_b->target = find_min(list_a);
		else
			list_b->target = target;
		list_b = list_b->next;
	}
}

static void	set_cost_b(t_list *list_a, t_list *list_b)
{
	int	len_a;
	int	len_b;

	len_a = list_len(list_a);
	len_b = list_len(list_b);
	while (list_b)
	{
		list_b->push_cost = list_b->index;
		if (!(list_b->above_median))
			list_b->push_cost = len_b - (list_b->index);
		if (list_b->target)
		{
			if (list_b->target->above_median)
				list_b->push_cost += list_b->target->index;
			else
				list_b->push_cost += len_a - (list_b->target->index);
		}
		list_b = list_b->next;
	}
}

void	prepare_list_b(t_list *list_a, t_list *list_b)
{
	position(list_a);
	position(list_b);
	set_target_b(list_a, list_b);
	set_cost_b(list_a, list_b);
}

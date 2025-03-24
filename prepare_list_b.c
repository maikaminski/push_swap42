/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_list_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:53:09 by makamins          #+#    #+#             */
/*   Updated: 2025/03/17 18:53:50 by makamins         ###   ########.fr       */
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
			if(a->value > list_b->value && a->value < largest)
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

void	prepare_list_b(t_list *list_a, t_list *list_b)
{
	position(list_a);
	position(list_b);
	set_target_b(list_a, list_b);
}

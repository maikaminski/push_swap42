/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:52:37 by makamins          #+#    #+#             */
/*   Updated: 2025/03/19 19:07:56 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_list **list_a)
{
	t_list	*biggest;

	if (is_sorted(*list_a))
		return ;
	biggest = find_max(*list_a);
	if (*list_a == biggest)
		ra(list_a);
	else if ((*list_a)->next == biggest)
		rra(list_a);
	if ((*list_a)->value > (*list_a)->next->value)
		sa(list_a);
}

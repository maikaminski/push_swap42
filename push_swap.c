/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:51:58 by makamins          #+#    #+#             */
/*   Updated: 2025/03/28 14:50:38 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **list_a, t_list **list_b)
{
	if (is_sorted(*list_a))
		return ;
	if (list_len(*list_a) == 3)
		three_numbers(list_a);
	if (list_len(*list_a) > 3)
		pb(list_b, list_a);
	if (list_len(*list_a) > 3)
		pb(list_b, list_a);
	while (list_len(*list_a) > 3)
	{
		prepare_list_a(*list_a, *list_b);
		move_cheapest_to_b(list_a, list_b);
	}
	three_numbers(list_a);
	while (*list_b)
	{
		prepare_list_b(*list_a, *list_b);
		move_cheapest_to_a(list_a, list_b);
	}
	finalize_sort(list_a);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_b = NULL;
	if (argc < 2)
		return (1);
	list_a = init_list(argc, argv);
	if (!list_a)
		return (1);
	push_swap(&list_a, &list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}

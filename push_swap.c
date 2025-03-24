/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:51:58 by makamins          #+#    #+#             */
/*   Updated: 2025/03/24 13:41:23 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **list_a, t_list **list_b)
{
	if (is_sorted(*list_a))
		return ;
	pb(list_b, list_a);
	pb(list_b, list_a);
	prepare_list_a(*list_a, *list_b);
	prepare_list_b(*list_a, *list_b);
	while (list_len(*list_a) > 3)
		pb(list_b, list_a);
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
	{
		ft_printf("ERROR: need more arguments.\n");
		return (1);
	}
	list_a = init_list(argc, argv);
	if (!list_a)
	{
		ft_printf("ERROR: failed to initialize list_a.\n");
		return (1);
	}
	push_swap(&list_a, &list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}

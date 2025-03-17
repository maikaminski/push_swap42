/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:02:54 by makamins          #+#    #+#             */
/*   Updated: 2025/03/17 17:13:01 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *listnew(int value)
{
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = -1;
    new_node->above_median = false;
    new_node->cheapest = false;
    new_node->target = NULL;
    new_node->prev = NULL;
    new_node->next = NULL;
    return (new_node);
}

void list_add_bottom(t_list **list, t_list *new_node)
{
    t_list *last_node;

    if (!*list)
    {
        *list = new_node;
        return ;
    }
    last_node = find_last(*list);
    last_node->next = new_node;
    new_node->prev = last_node;
}

t_list	*init_list(int argc, char **argv)
{
	t_list	*list;
	t_list	*new_node;
	int		i;
	long	value;

	list = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN || ! only_numbers(argv[i]) || !check_duplicate(list, value))
		{
			ft_printf("ERROR\n");
			exit(1);
		}
		new_node = list_new(value);
		if (!new_node)
		{
			ft_printf("ERROR\n");
			exit(1);
		}
		list_add_bottom(&list, new_node);
		i++;
	}
	return (list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:02:54 by makamins          #+#    #+#             */
/*   Updated: 2025/03/27 16:03:14 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		signal;
	long	result;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	signal = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result * signal > INT_MAX || result * signal < INT_MIN)
			exit(1);
		i++;
	}
	if (nptr[i] != '\0' && !ft_isdigit(nptr[i]))
		exit(1);
	return ((int)(result * signal));
}

t_list	*list_new(int value)
{
	t_list	*new_node;

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

void	list_add_bottom(t_list **list, t_list *new_node)
{
	t_list	*last_node;

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
		if (value > INT_MAX || value < INT_MIN || !only_numbers(argv[i]) \
				|| !check_duplicate(list, value))
			cleanup_and_exit(&list);
		new_node = list_new(value);
		if (!new_node)
			cleanup_and_exit(&list);
		list_add_bottom(&list, new_node);
		i++;
	}
	return (list);
}

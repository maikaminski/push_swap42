/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:09:52 by makamins          #+#    #+#             */
/*   Updated: 2025/03/27 15:07:35 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_list	*list)
{
	t_list	*current;
	int		i;

	if (!list)
		return (0);
	current = list;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_list	*find_last(t_list *list)
{
	t_list	*current;

	if (!list)
		return (NULL);
	current = list;
	while (current->next)
		current = current->next;
	return (current);
}

t_list	*find_max(t_list *list)
{
	t_list	*node;
	long	max;

	if (!list)
		return (NULL);
	max = LONG_MIN;
	while (list)
	{
		if (list->value > max)
		{
			max = list->value;
			node = list;
		}
		list = list->next;
	}
	return (node);
}

t_list	*find_min(t_list *list)
{
	t_list	*node;
	long	min;

	if (!list)
		return (NULL);
	min = LONG_MAX;
	while (list)
	{
		if (list->value < min)
		{
			min = list->value;
			node = list;
		}
		list = list->next;
	}
	return (node);
}

bool	is_sorted(t_list *list)
{
	while (list->next)
	{
		if (list->value > list->next->value)
			return (false);
		list = list->next;
	}
	return (true);
}

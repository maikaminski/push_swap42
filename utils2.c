/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:26:41 by makamins          #+#    #+#             */
/*   Updated: 2025/03/17 16:54:57 by makamins         ###   ########.fr       */
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

int	ft_list_size(t_list *list)
{
	t_list	*node;
	int		count;

	count = 0;
	node = list;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}
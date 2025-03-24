/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:59:09 by makamins          #+#    #+#             */
/*   Updated: 2025/03/24 13:40:00 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// somente números
bool	only_numbers(char *arg)
{
	int	i;

	i = 0;
	if (arg == NULL || arg[0] == '\0')
		return (false);
	if ((arg[i] == '+' || arg[i] == '-') && arg[i + 1] != '\0')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

//somente números diferentes
bool	check_duplicate(t_list *list, int nbr)
{
	// if (!list)
	// 	return (false);
	while (list)
	{
		if (list->value == nbr)
			return (false);
		list = list->next;
	}
	return (true);
}

// free
void free_list(t_list **list)
{
    t_list *temp;

    while (*list)
    {
        temp = (*list)->next;
        free(*list);
        *list = temp;
    }
}

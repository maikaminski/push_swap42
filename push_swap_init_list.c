/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:02:54 by makamins          #+#    #+#             */
/*   Updated: 2025/03/24 13:48:29 by makamins         ###   ########.fr       */
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

int ft_atoi(const char *nptr)
{
    int i;
    int signal;
    long result;

    i = 0;
    // Ignora espaços iniciais
    while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
        i++;
    // Verifica o sinal
    signal = 1;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            signal = -1;
        i++;
    }
    // Converte os dígitos
    result = 0;
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        // Verifica overflow
        if (result * signal > INT_MAX || result * signal < INT_MIN)
        {
            ft_printf("Error: Value out of range\n");
            exit(1);
        }
        i++;
    }
    // Verifica se há caracteres não numéricos após os dígitos
    if (nptr[i] != '\0' && !ft_isdigit(nptr[i]))
    {
        ft_printf("Error: Invalid character found: %c\n", nptr[i]);
        exit(1);
    }
    return ((int)(result * signal));
}

t_list *list_new(int value)
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

// t_list	*init_list(int argc, char **argv)
// {
// 	t_list	*list;
// 	t_list	*new_node;
// 	int		i;
// 	long	value;

// 	list = NULL;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		value = ft_atoi(argv[i]);
// 		if (value > INT_MAX || value < INT_MIN || ! only_numbers(argv[i]) || !check_duplicate(list, value))
// 		{
// 			ft_printf("ERROR1\n");
// 			exit(1);
// 		}
// 		new_node = list_new(value);
// 		if (!new_node)
// 		{
// 			ft_printf("ERROR2\n");
// 			exit(1);
// 		}
// 		list_add_bottom(&list, new_node);
// 		i++;
// 	}
// 	return (list);
// }

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
		
		if (value > INT_MAX || value < INT_MIN || !only_numbers(argv[i]))
		{
			ft_printf("ERROR: Invalid value or format\n");
			exit(1);
		}
		if (!check_duplicate(list, value))
		{
			ft_printf("ERROR: Duplicate value found: %d\n", value); // Debug
			exit(1);
		}
		new_node = list_new(value);
		if (!new_node)
		{
			ft_printf("ERROR: Memory allocation failed\n");
			exit(1);
		}
		list_add_bottom(&list, new_node);
		i++;
	}
	return (list);
}
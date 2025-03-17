/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:52:01 by makamins          #+#    #+#             */
/*   Updated: 2025/03/14 16:15:27 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_list
{
	int				push_cost;
	int				value;
	int				index;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*prev;	
	struct s_list	*next;
}	t_list;

//moves

void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_b, t_list **list_a);
void	rra(t_list **list_a);
void	rrb(t_list **list_b);
void	rrr(t_list **list_a, t_list **list_b);
void	ra(t_list **list_a);
void	rb(t_list **list_b);
void	rr(t_list **list_a, t_list **list_b);
void	sa(t_list **list);
void	sb(t_list **list);
void	ss(t_list **list_a, t_list **list_b);

//sorter

void	three_numbers(t_list **list_a);

//validations

bool	only_numbers(char *arg);
bool	check_duplicate(t_list *list, int nbr);

//utils

int		list_len(t_list	*list);
t_list	*find_last(t_list *list);
t_list	*find_max(t_list *list);
t_list	*find_min(t_list *list);
bool	is_sorted(t_list *list);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:52:01 by makamins          #+#    #+#             */
/*   Updated: 2025/03/27 15:04:19 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"

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
void	three_numbers(t_list **list_a);
void	push_swap(t_list **list_a, t_list **list_b);
bool	only_numbers(char *arg);
bool	check_duplicate(t_list *list, int nbr);
void	free_list(t_list **list);
void	prepare_list_a(t_list *list_a, t_list *list_b);
void	prepare_list_b(t_list *list_a, t_list *list_b);
int		list_len(t_list	*list);
bool	is_sorted(t_list *list);
void	position(t_list *list);
t_list	*init_list(int argc, char **argv);
void	move_cheapest_to_b(t_list **list_a, t_list **list_b);
void	finalize_sort(t_list **list_a);
void	set_target_a(t_list *list_a, t_list *list_b);
void	set_target_b(t_list *list_a, t_list *list_b);
t_list	*list_new(int value);
void	list_add_bottom(t_list **list, t_list *new_node);
t_list	*init_list(int argc, char **argv);
void	move_cheapest_to_a(t_list **list_a, t_list **list_b);
void	move_cheapest_to_b(t_list **list_a, t_list **list_b);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
t_list	*find_last(t_list *list);
t_list	*find_max(t_list *list);
t_list	*find_min(t_list *list);
t_list	*find_closest_smaller(t_list *list_b, int value);
t_list	*find_cheapest(t_list *list_b);

#endif
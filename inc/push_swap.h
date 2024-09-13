/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:00:38 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/13 17:09:18 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int	val;
	int	index;
	int	push_cost;
	bool	above_med;
	bool	cheapest;
	struct s_node *target_node;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

//arg handler
int input_checker(char *av);
int	duplicate_check(t_node *a, int n);
void free_error(t_node **a);
void free_stack(t_node **stack);

//commands: SORT
void	simple_sort(t_node **a);
void complex_sort(t_node **a, t_node **b);

//commands: movements : push
void pa(t_node **a, t_node **b, bool print);
void pb(t_node **b, t_node **a, bool print);

//commands: movements : rotate
void 	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);

//commands: movements : reverse_rotate
void rra(t_node **a, bool print);
void rrb(t_node **b, bool print);
void rrr(t_node **a, t_node **b, bool print);

//commands: movements : swap
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);

//stack management
void	current_index(t_node *stack);
void 	set_cheapest(t_node *stack);
void	prep_for_push(t_node **stack, t_node *top_node, char stack_id);
void	current_index(t_node *stack);
void	init_nodes_b(t_node *a, t_node *b);
bool	stack_sorted(t_node *stack);
void	add_node(t_node **stack, int n);
void		init_stack_a(t_node	**a, char **av);
t_node *get_last_node(t_node *stack);
int	stack_len(t_node *stack);
t_node	*find_max(t_node *stack);
t_node *find_min(t_node *stack);
void	refresh_nodes_a(t_node *a, t_node *b);
t_node *get_cheapest(t_node *stack);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:00:38 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/12 21:58:36 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/libft.h"
# include "libft/inc/ft_printf.h"
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




#endif
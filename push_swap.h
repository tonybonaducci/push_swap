/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:00:38 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/02 14:58:22 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libft/inc/libft.h"
# include "libft/inc/ft_printf.h"
# include "limits.h"

typedef struct s_node
{
	int	nb;
	int	index;
	int	cost;
	bool	abv_avg;
	bool 	cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;




#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:57:57 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 23:20:37 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*lowest_node;

	lowest_node = get_lowest_cost(*a);
	if (lowest_node->median && lowest_node->target_node->median)
		rotate_lowest_top(a, b, lowest_node);
	else if (!(lowest_node->median) && !(lowest_node->target_node->median))
		rev_rotate_lowest_top(a, b, lowest_node);
	top_lowest_node(a, lowest_node, 'a');
	top_lowest_node(b, lowest_node->target_node, 'b');
	pb(b, a);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	top_lowest_node(a, (*b)->target_node, 'a');
	pa(a, b);
}

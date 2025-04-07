/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:13:00 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 21:29:42 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_lowest_top(t_node **a, t_node **b, t_node *lowest_node)
{
	while (*a != lowest_node && *b != lowest_node->target_node)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

void	rev_rotate_lowest_top(t_node **a, t_node **b, t_node *lowest_node)
{
	while (*a != lowest_node && *b != lowest_node->target_node)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	top_lowest_node(t_node **stack, t_node *lowest_node, char name)
{
	while (*stack != lowest_node)
	{
		if (name == 'a')
		{
			if (lowest_node->median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (lowest_node->median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

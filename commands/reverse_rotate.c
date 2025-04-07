/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:39:18 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 18:46:56 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate_node(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = get_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_node **a)
{
	reverse_rotate_node(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	reverse_rotate_node(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate_node(a);
	reverse_rotate_node(b);
	ft_printf("rrb\n");
}

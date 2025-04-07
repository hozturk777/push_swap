/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:15:51 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 18:34:15 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_node(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_node **a)
{
	rotate_node(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate_node(b);
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate_node(a);
	rotate_node(b);
	ft_printf("rr\n");
}

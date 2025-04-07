/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:32:22 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 23:19:44 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_index(t_node *stack)
{
	int	is_index;
	int	is_median;

	is_index = 0;
	if (!stack)
		return ;
	is_median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = is_index;
		if (is_index <= is_median)
			stack->median = 1;
		else
			stack->median = 0;
		stack = stack->next;
	}
}

static void	define_target_a(t_node *a, t_node *b)
{
	t_node	*b_node;
	t_node	*target_node;
	long	target_num;

	while (a)
	{
		target_num = LONG_MIN;
		b_node = b;
		while (b_node)
		{
			if (b_node->num < a->num && b_node->num > target_num)
			{
				target_num = b_node->num;
				target_node = b_node;
			}
			b_node = b_node->next;
		}
		if (target_num == LONG_MIN)
			a->target_node = get_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	set_push_cost(t_node *a, t_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->median))
			a->push_cost = a_len - a->index;
		if (a->target_node->median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += b_len - a->target_node->index;
		a = a->next;
	}
}

void	find_lowest_cost(t_node *stack)
{
	long	lowest_cost;
	t_node	*lowest_node;

	if (!stack)
		return ;
	lowest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < lowest_cost)
		{
			lowest_cost = stack->push_cost;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	lowest_node->lowest_cost = 1;
}

void	setup_a(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	define_target_a(a, b);
	set_push_cost(a, b);
	find_lowest_cost(a);
}

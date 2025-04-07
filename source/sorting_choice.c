/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:12:21 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 23:38:59 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_sorted(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	sort_three_node(t_node **a)
{
	t_node	*max_node;

	max_node = get_max_node(*a);
	if (max_node == *a)
		ra(a);
	else if (max_node == (*a)->next)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

void	sort_nodes(t_node **a, t_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && check_sorted(*a))
		pb(b, a);
	if (len-- > 3 && check_sorted(*a))
		pb(b, a);
	while (len-- > 3 && check_sorted(*a))
	{
		setup_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three_node(a);
	while (*b)
	{
		setup_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	top_min_node(a);
}

void	sort_select(t_node **a, t_node **b)
{
	if (check_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three_node(a);
		else
			sort_nodes(a, b);
	}
}

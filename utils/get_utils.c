/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:51:22 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/11 15:11:45 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_node	*get_max_node(t_node *stack)
{
	long	max_num;
	t_node	*max_node;

	max_num = LONG_MIN;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->num > max_num)
		{
			max_num = stack->num;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node	*get_min_node(t_node *stack)
{
	long	min_num;
	t_node	*min_node;

	min_num = LONG_MAX;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->num < min_num)
		{
			min_num = stack->num;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	*get_lowest_cost(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->lowest_cost)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:51:22 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 18:35:25 by hsyn             ###   ########.fr       */
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

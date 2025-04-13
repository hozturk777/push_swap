/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:13:52 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/11 15:10:46 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_node **dest, t_node **source)
{
	t_node	*node;

	if (!*source)
		return ;
	node = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	node->prev = NULL;
	if (!*dest)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}

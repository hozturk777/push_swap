/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:36:53 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 16:42:09 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void	swap_nodes(t_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_node **a)
{
	swap_nodes(a);
	ft_printf("sa\n");
}

void	sb(t_node **b)
{
	swap_nodes(b);
	ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap_nodes(a);
	swap_nodes(b);
	ft_printf("ss\n");
}
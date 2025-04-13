/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortb_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:00:46 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/11 15:12:04 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	define_target_b(t_node *a, t_node *b)
{
	t_node	*a_node;
	t_node	*target_node;
	long	target_num;

	while (b)
	{
		target_num = LONG_MAX;
		a_node = a;
		while (a_node)
		{
			if (a_node->num > b->num && a_node->num < target_num)
			{
				target_num = a_node->num;
				target_node = a_node;
			}
			a_node = a_node->next;
		}
		if (target_num == LONG_MAX)
			b->target_node = get_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	setup_b(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	define_target_b(a, b);
}

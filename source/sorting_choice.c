/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:12:21 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/06 19:19:30 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_select(t_node *a, t_node *b)
{
	if (!check_sorted(*a))
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three_node(a);
	else
		sort_nodes(a, b);
}

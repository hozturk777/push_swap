/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:48:34 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 18:06:12 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}


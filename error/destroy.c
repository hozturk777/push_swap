/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:46 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 16:05:49 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_node **stack)
{
	t_node	*next_tmp;
	t_node	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		next_tmp = node->next;
		node->num = 0;
		free(node);
		node = next_tmp;
	}
	*stack = NULL;
}
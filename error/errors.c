/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:29:37 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/07 16:31:51 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

void	put_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	error_control(t_node **a, char **str, int flag)
{
	if (flag)
		free_split(str);
	free_stack(a);
	put_error();
}

void	check_null(void *ptr)
{
	if (!ptr)
		put_error();
	else
		return ;
}

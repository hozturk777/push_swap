/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:29:37 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/11 15:11:12 by huozturk         ###   ########.fr       */
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

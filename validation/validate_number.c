/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:54:11 by hsyn              #+#    #+#             */
/*   Updated: 2025/04/06 22:41:50 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	zero_int_check(char *str)
{
	int	i;

	i = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	while (*str)
	{
		str++;
		i++;
	}
	if (i > 11)
		return (1);
	else
		return (0);
}

int	check_valid_number(char *str)
{
	if (zero_int_check(str))
		return (1);
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (1);
	if ((*str == '+' || *str == '-'))
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

int	is_duplicate(t_node *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == num)
			return (1);
	}
	return (0);
}
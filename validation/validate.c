/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:17:25 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/11 15:12:23 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_whitespaces(const char **str)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
}

static	int	ft_atol(const char *str, int *nbr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	ft_whitespaces(&str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	else
	{
		*nbr = (int)result;
		return (0);
	}
}

static int	build_stack(t_node **stack, int num)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return (1);
	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (1);
	node->next = NULL;
	node->num = num;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (0);
}

void	validate_and_build(t_node **a, char **av, int flag)
{
	int		nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		nbr = 0;
		if (check_valid_number(av[i]))
			error_control(a, av, flag);
		if (ft_atol(av[i], &nbr))
			error_control(a, av, flag);
		if (is_duplicate(*a, nbr))
			error_control(a, av, flag);
		if (build_stack(a, nbr))
			error_control(a, av, flag);
		i++;
	}
	if (flag)
		free_split(av);
}

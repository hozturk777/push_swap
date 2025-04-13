/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:19:38 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/13 13:00:43 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	else if (ac == 2 && !av[1][0])
		put_error();
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		validate_and_build(&a, av, 1);
	}
	else
		validate_and_build(&a, av + 1, 0);
	check_null(a);
	sort_select(&a, &b);
	free_stack(&a);
	return (0);
}

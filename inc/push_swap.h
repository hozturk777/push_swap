/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:55:57 by huozturk          #+#    #+#             */
/*   Updated: 2025/04/13 13:00:55 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807
# endif

# ifndef LONG_MIN
#  define LONG_MIN -9223372036854775807
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_node
{
	int				num;
	int				index;
	int				push_cost;
	int				lowest_cost;
	int				median;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int			check_valid_number(char	*str);
int			is_duplicate(t_node *a, int num);
int			stack_len(t_node *stack);

t_node		*get_lowest_cost(t_node *stack);
t_node		*get_last_node(t_node *stack);
t_node		*get_min_node(t_node *stack);
t_node		*get_max_node(t_node *stack);

void		free_stack(t_node **stack);
void		error_control(t_node **a, char **str, int flag);
void		put_error(void);
void		free_split(char	**str);
void		validate_and_build(t_node **a, char **av, int flag);
void		setup_a(t_node *a, t_node *b);
void		setup_b(t_node *a, t_node *b);
void		set_index(t_node *stack);
void		find_lowest_cost(t_node *stack);
void		top_lowest_node(t_node **stack, t_node *lowest_node, char name);
void		sort_nodes(t_node **a, t_node **b);
void		move_b_to_a(t_node **a, t_node **b);
void		move_a_to_b(t_node **a, t_node **b);
void		check_null(void	*ptr);
void		sort_select(t_node **a, t_node **b);
void		rotate_lowest_top(t_node **a, t_node **b, t_node *lowest_node);
void		rev_rotate_lowest_top(t_node **a, t_node **b, t_node *lowest_node);
void		top_min_node(t_node **a);

void		sa(t_node **a);
void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **a, t_node **b);
void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);
void		pa(t_node **a, t_node **b);
void		pb(t_node **b, t_node **a);

#endif

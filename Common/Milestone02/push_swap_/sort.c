/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:26:36 by bakpulat          #+#    #+#             */
/*   Updated: 2025/03/20 12:17:49 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_target_closer(t_stack *a, t_stack *b)
{
	int		min;
	t_stack	*stack_b;

	while (a)
	{
		min = INT_MIN;
		stack_b = b;
		a->target = max_node(b);
		while (stack_b)
		{
			if (a->num > stack_b->num && stack_b->num >= min)
			{
				min = stack_b->num;
				a->target = stack_b;
			}
			stack_b = stack_b->next;
		}
		a = a->next;
	}
}

static void	max_target_closer(t_stack *b, t_stack *a)
{
	int		max;
	t_stack	*stack_a;

	while (b)
	{
		max = INT_MAX;
		stack_a = a;
		b->target = min_node(a);
		while (stack_a)
		{
			if (b->num < stack_a->num && stack_a->num <= max)
			{
				max = stack_a->num;
				b->target = stack_a;
			}
			stack_a = stack_a->next;
		}
		b = b->next;
	}
}

static void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*best_node;

	best_node = get_best_min_mov(*a);
	if (best_node->above_median == best_node->target->above_median)
	{
		if (best_node->above_median)
		{
			while (*a != best_node && *b != best_node->target)
				rr(a, b, 0);
		}
		else
		{
			while (*a != best_node && *b != best_node->target)
				rrr(a, b, 0);
		}
	}
	best_min_move_on_top(a, best_node, 1);
	best_min_move_on_top(b, best_node->target, 0);
	pb(a, b, 0);
}

static void	b_to_a(t_stack **a, t_stack **b)
{
	best_min_move_on_top(a, (*b)->target, 1);
	pa(b, a, 0);
}

void	sort(t_stack **a, t_stack **b)
{
	int	len;
	int	i;

	i = 0;
	len = stack_len(*a);
	while (i++ < 2 && len-- > 3 && !is_sorted(*a))
		pb(a, b, 0);
	while (len-- > 3 && !is_sorted(*a))
	{
		set_pos(*a);
		set_pos(*b);
		min_target_closer(*a, *b);
		set_min_mov(*a, *b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_pos(*a);
		set_pos(*b);
		max_target_closer(*b, *a);
		b_to_a(a, b);
	}
	min_on_top(a);
}

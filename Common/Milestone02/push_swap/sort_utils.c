/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:28:59 by bakpulat          #+#    #+#             */
/*   Updated: 2025/03/20 12:17:47 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	max;

	max = max_node(*a)->num;
	if ((*a)->num == max)
		ra(a, 0);
	else if ((*a)->next->num == max)
		rra(a, 0);
	if ((*a)->next->num < (*a)->num)
		sa(a, 0);
}

void	set_pos(t_stack *stack)
{
	int	med;
	int	i;

	i = 0;
	med = stack_len(stack);
	if (med % 2 == 0)
		med /= 2;
	else
		med = (med + 1) / 2;
	while (stack)
	{
		if (i < med)
		{
			stack->above_median = 1;
			stack->pos = i;
		}
		else
		{
			stack->above_median = 0;
			stack->pos = i;
		}
		i++;
		stack = stack->next;
	}
}

t_stack	*get_best_min_mov(t_stack *stack)
{
	int		min_mov;
	t_stack	*node_min_mov;

	if (!stack)
		return (NULL);
	min_mov = INT_MAX;
	while (stack)
	{
		if (stack->min_mov < min_mov)
		{
			min_mov = stack->min_mov;
			node_min_mov = stack;
		}
		stack = stack->next;
	}
	return (node_min_mov);
}

void	best_min_move_on_top(t_stack **stack, t_stack *best_min_node, int a)
{
	while (*stack != best_min_node)
	{
		if (best_min_node->above_median)
		{
			if (a)
				ra(stack, 0);
			else
				rb(stack, 0);
		}
		else
		{
			if (a)
				rra(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	min_on_top(t_stack **a)
{
	t_stack	*node_min;

	node_min = min_node(*a);
	while (*a != node_min)
	{
		if (node_min->above_median)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

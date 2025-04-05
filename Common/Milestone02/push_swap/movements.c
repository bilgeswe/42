/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:26:07 by bakpulat          #+#    #+#             */
/*   Updated: 2025/03/20 12:17:42 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	movements(t_stack *stack)
{
	int	len;

	len = stack_len(stack);
	while (stack)
	{
		if (stack->above_median)
			stack->min_mov = stack->pos;
		else
			stack->min_mov = len - stack->pos;
		stack = stack->next;
	}
}

static void	sum_target_movement(t_stack *a)
{
	while (a)
	{
		if (a->above_median == a->target->above_median
			&& a->min_mov < a->target->min_mov)
			a->min_mov = a->target->min_mov;
		else if (a->above_median != a->target->above_median)
			a->min_mov = a->min_mov + a->target->min_mov;
		a = a->next;
	}
}

void	set_min_mov(t_stack *a, t_stack *b)
{
	movements(a);
	movements(b);
	sum_target_movement(a);
}

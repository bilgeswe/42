/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:29:15 by bakpulat          #+#    #+#             */
/*   Updated: 2025/03/20 15:04:48 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_last_node(*stack);
	first_node = *stack;
	last_node->next = *stack;
	last_node->prev->next = NULL;
	first_node->prev = last_node;
	*stack = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	rra(t_stack **a, int check)
{
	reverse(a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int check)
{
	reverse(b);
	if (!check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int check)
{
	reverse(a);
	reverse(b);
	if (!check)
		write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:38:59 by bakpulat          #+#    #+#             */
/*   Updated: 2025/02/27 11:39:01 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	t_stack_node	*node_to_move;

	if (!a || !b || !*a)
		return ;
	node_to_move = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	node_to_move->next = *b;
	if (*b)
		(*b)->prev = node_to_move;
	*b = node_to_move;
	node_to_move->prev = NULL;
	if (!print)
		ft_putstr_fd("pb\n", 1);
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	t_stack_node	*node_to_move;

	if (!a || !b || !*b)
		return ;
	node_to_move = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	node_to_move->next = *a;
	if (*a)
		(*a)->prev = node_to_move;
	*a = node_to_move;
	node_to_move->prev = NULL;
	if (!print)
		ft_putstr_fd("pa\n", 1);
}

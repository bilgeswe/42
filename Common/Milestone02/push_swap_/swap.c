/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:28:43 by bakpulat          #+#    #+#             */
/*   Updated: 2025/03/20 15:05:55 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*aux;

	if (*stack || (*stack)->next)
	{
		aux = *stack;
		*stack = (*stack)->next;
		aux->next = (*stack)->next;
		(*stack)->next = aux;
		if (aux->next)
			aux->next->prev = aux;
		aux->prev = *stack;
		(*stack)->prev = NULL;
	}
}

void	sa(t_stack **a, int check)
{
	if (!*a)
		return ;
	swap(a);
	if (!check)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int check)
{
	if (!*b)
		return ;
	swap(b);
	if (!check)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int check)
{
	if (!*b || !*a)
		return ;
	swap(a);
	swap(b);
	if (!check)
		write(1, "ss\n", 3);
}

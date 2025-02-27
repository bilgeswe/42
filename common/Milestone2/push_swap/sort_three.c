/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:20:30 by jbyrne            #+#    #+#             */
/*   Updated: 2025/02/27 11:39:52 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		ra(a, false);
	else if (biggest == (*a)->next)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;
	long			max_so_far;

	if (!stack)
		return (NULL);
	max_so_far = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max_so_far)
		{
			max_so_far = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

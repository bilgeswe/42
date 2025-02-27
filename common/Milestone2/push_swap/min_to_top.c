/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:19:50 by jbyrne            #+#    #+#             */
/*   Updated: 2025/02/27 11:39:45 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_to_top(t_stack_node **a)
{
	int	i;

	i = find_index(*a, min_nbr(*a));
	if (i < stack_len(*a) - i)
	{
		while ((*a)->nbr != min_nbr(*a))
			ra(a, false);
	}
	else
	{
		while ((*a)->nbr != min_nbr(*a))
			rra(a, false);
	}
}

int	min_nbr(t_stack_node *a)
{
	int	min;

	min = a->nbr;
	while (a)
	{
		if (min > a->nbr)
			min = a->nbr;
		a = a->next;
	}
	return (min);
}

int	max_nbr(t_stack_node *a)
{
	int	max;

	max = a->nbr;
	while (a)
	{
		if (max < a->nbr)
			max = a->nbr;
		a = a->next;
	}
	return (max);
}

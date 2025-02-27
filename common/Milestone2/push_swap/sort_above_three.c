/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:20:04 by jbyrne            #+#    #+#             */
/*   Updated: 2025/02/27 11:39:48 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_push_to_b(t_stack_node **a, t_stack_node **b)
{
	int				cheapest;
	t_stack_node	*tmp;

	while (stack_len(*a) > 3 && !stack_is_sorted(*a))
	{
		tmp = *a;
		cheapest = find_cheapest_ab(*a, *b);
		while (cheapest >= 0)
		{
			if (cheapest == calc_left_rotate_ab(*a, *b, tmp->nbr))
				cheapest = do_left_ab(a, b, tmp->nbr);
			else if (cheapest == calc_right_rotate_ab(*a, *b, tmp->nbr))
				cheapest = do_right_ab(a, b, tmp->nbr);
			else
				tmp = tmp->next;
		}
	}
}

void	sort_push_to_a(t_stack_node **a, t_stack_node **b)
{
	int				cheapest;
	t_stack_node	*tmp;

	while (*b)
	{
		tmp = *b;
		cheapest = find_cheapest_ba(*a, *b);
		while (cheapest >= 0)
		{
			if (cheapest == calc_left_rotate_ba(*b, *a, tmp->nbr))
				cheapest = do_left_ba(b, a, tmp->nbr);
			else if (cheapest == calc_right_rotate_ba(*b, *a, tmp->nbr))
				cheapest = do_right_ba(b, a, tmp->nbr);
			else
				tmp = tmp->next;
		}
	}
}

void	sort_above_three(t_stack_node **a)
{
	t_stack_node	*b;

	b = NULL;
	if (stack_len(*a) > 3 && !stack_is_sorted(*a))
		pb(a, &b, false);
	if (stack_len(*a) > 3 && !stack_is_sorted(*a))
		pb(a, &b, false);
	if (stack_len(*a) > 3 && !stack_is_sorted(*a))
		sort_push_to_b(a, &b);
	if (!stack_is_sorted(*a))
		sort_three(a);
	sort_push_to_a(a, &b);
	min_to_top(a);
}

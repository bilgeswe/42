/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:38:33 by bakpulat          #+#    #+#             */
/*   Updated: 2025/02/27 11:38:38 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_left_rotate_ab(t_stack_node *a, t_stack_node *b, int nbr)
{
	int	operations;

	operations = 0;
	if (find_index(a, nbr) == find_place_for_b(b, nbr))
		operations = find_index(a, nbr);
	else if (find_index(a, nbr) > find_place_for_b(b, nbr))
		operations = find_index(a, nbr);
	else if (find_index(a, nbr) < find_place_for_b(b, nbr))
		operations = find_place_for_b(b, nbr);
	return (operations);
}

int	do_left_ab(t_stack_node **a, t_stack_node **b, int nbr)
{
	while (find_index((*a), nbr) != 0 && find_place_for_b((*b), nbr) != 0)
	{
		rr(a, b, false);
	}
	while (find_index((*a), nbr) != 0)
	{
		ra(a, false);
	}
	while (find_place_for_b((*b), nbr) != 0)
		rb(b, false);
	pb(a, b, false);
	return (-1);
}

int	calc_right_rotate_ab(t_stack_node *a, t_stack_node *b, int nbr)
{
	int	operations;
	int	sz_a;
	int	sz_b;

	operations = 0;
	sz_a = stack_len(a);
	sz_b = stack_len(b);
	if (find_index(a, nbr) == (sz_a - 1) && find_place_for_b(b, nbr) == (sz_b
			- 1))
		operations = 1;
	if (sz_a - find_index(a, nbr) == sz_b - find_place_for_b(b, nbr))
		operations = sz_a - find_index(a, nbr);
	if (sz_a - find_index(a, nbr) > sz_b - find_place_for_b(b, nbr))
		operations = sz_a - find_index(a, nbr);
	if (sz_b - find_place_for_b(b, nbr) > sz_a - find_index(a, nbr))
		operations = sz_b - find_place_for_b(b, nbr);
	return (operations);
}

int	do_right_ab(t_stack_node **a, t_stack_node **b, int nbr)
{
	while (find_index((*a), nbr) != 0 && find_place_for_b((*b), nbr) != 0)
		rrr(a, b, false);
	while (stack_len(*a) - find_index((*a), nbr) != stack_len(*a))
		rra(a, false);
	while (stack_len(*b) - find_place_for_b((*b), nbr) != stack_len(*b))
		rrb(b, false);
	pb(a, b, false);
	return (-1);
}

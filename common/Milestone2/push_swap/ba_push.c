/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ba_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:38:44 by bakpulat          #+#    #+#             */
/*   Updated: 2025/02/27 11:38:45 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	do_right_ba(t_stack_node **b, t_stack_node **a, int nbr)
{
	while (find_index((*b), nbr) != 0 && find_place_for_a((*a), nbr) != 0)
		rrr(a, b, false);
	while (stack_len(*b) - find_index((*b), nbr) != stack_len(*b))
		rrb(b, false);
	while (stack_len(*a) - find_place_for_a((*a), nbr) != stack_len(*a))
		rra(a, false);
	pa(a, b, false);
	return (-1);
}

int	calc_right_rotate_ba(t_stack_node *b, t_stack_node *a, int nbr)
{
	int	operations;
	int	sz_a;
	int	sz_b;

	operations = 0;
	sz_a = stack_len(a);
	sz_b = stack_len(b);
	if (find_index(b, nbr) == (sz_b - 1) && find_place_for_a(a, nbr) == (sz_a
			- 1))
		operations = 1;
	if (sz_b - find_index(b, nbr) == sz_a - find_place_for_a(a, nbr))
		operations = sz_b - find_index(b, nbr);
	if (sz_b - find_index(b, nbr) > sz_a - find_place_for_a(a, nbr))
		operations = sz_b - find_index(b, nbr);
	if (sz_a - find_place_for_a(a, nbr) > sz_b - find_index(b, nbr))
		operations = sz_a - find_place_for_a(a, nbr);
	return (operations);
}

int	do_left_ba(t_stack_node **b, t_stack_node **a, int nbr)
{
	while (find_index((*b), nbr) != 0 && find_place_for_a((*a), nbr) != 0)
		rr(a, b, false);
	while (find_index((*b), nbr) != 0)
		rb(b, false);
	while (find_place_for_a((*a), nbr) != 0)
		ra(a, false);
	pa(a, b, false);
	return (-1);
}

int	calc_left_rotate_ba(t_stack_node *b, t_stack_node *a, int nbr)
{
	int	operations;

	operations = 0;
	if (find_index(b, nbr) == find_place_for_a(a, nbr))
		operations = find_index(b, nbr);
	else if (find_index(b, nbr) > find_place_for_a(a, nbr))
		operations = find_index(b, nbr);
	else if (find_index(b, nbr) < find_place_for_a(a, nbr))
		operations = find_place_for_a(a, nbr);
	return (operations);
}

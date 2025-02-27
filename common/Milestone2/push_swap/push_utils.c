/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:38:51 by bakpulat          #+#    #+#             */
/*   Updated: 2025/02/27 11:38:54 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest_ba(t_stack_node *a, t_stack_node *b)
{
	int				no_of_ops;
	t_stack_node	*tmp;

	tmp = b;
	no_of_ops = calc_left_rotate_ba(b, a, b->nbr);
	while (tmp)
	{
		if (no_of_ops > calc_left_rotate_ba(b, a, b->nbr))
			no_of_ops = calc_left_rotate_ba(b, a, b->nbr);
		if (no_of_ops > calc_right_rotate_ba(b, a, tmp->nbr))
			no_of_ops = calc_right_rotate_ba(b, a, tmp->nbr);
		tmp = tmp->next;
	}
	return (no_of_ops);
}

int	find_place_for_a(t_stack_node *stack_a, int nbr_push)
{
	int				i;
	t_stack_node	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > max_nbr(stack_a) || nbr_push < min_nbr(stack_a))
		i = find_index(stack_a, min_nbr(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

int	find_cheapest_ab(t_stack_node *a, t_stack_node *b)
{
	int				no_of_ops;
	t_stack_node	*tmp;

	tmp = a;
	no_of_ops = calc_left_rotate_ab(a, b, a->nbr);
	while (tmp)
	{
		if (no_of_ops > calc_left_rotate_ab(a, b, tmp->nbr))
			no_of_ops = calc_left_rotate_ab(a, b, tmp->nbr);
		if (no_of_ops > calc_right_rotate_ab(a, b, tmp->nbr))
			no_of_ops = calc_right_rotate_ab(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (no_of_ops);
}

int	find_place_for_b(t_stack_node *stack_b, int nbr_push)
{
	int				i;
	t_stack_node	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > max_nbr(stack_b) || nbr_push < min_nbr(stack_b))
	{
		i = find_index(stack_b, max_nbr(stack_b));
		return (i);
	}
	else
	{
		tmp = stack_b->next;
		while (nbr_push > stack_b->nbr || nbr_push < tmp->nbr)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

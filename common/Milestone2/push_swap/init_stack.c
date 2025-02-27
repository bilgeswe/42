/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:23:22 by jbyrne            #+#    #+#             */
/*   Updated: 2025/02/27 15:43:06 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX)
			return ((long)INT_MAX + 1);
		if (result * sign < INT_MIN)
			return ((long)INT_MIN - 1);
		str++;
	}
	return (result * sign);
}

int	is_number_out_of_range(const char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	return (0);
}

void	init_a_stack(t_stack_node **a, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]) || is_number_out_of_range(argv[i]))
		{
			free_error(a);
			return ;
		}
		nbr = ft_atol(argv[i]);
		if (nbr > LONG_MAX || nbr < LONG_MIN || duplicate_error(*a, (int)nbr))
		{
			free_error(a);
			return ;
		}
		append_node(a, (int)nbr);
		i++;
	}
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
	{
		free_error(stack);
		return ;
	}
	new_node->nbr = n;
	new_node->next = NULL;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

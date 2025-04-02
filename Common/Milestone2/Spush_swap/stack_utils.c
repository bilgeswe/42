/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:03:00 bakpulat             #+#    #+#             */
/*   Updated: 2024/02/07 12:03:00 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_node(int value)
{
    t_stack *node;
    
    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

int parse_args(t_stack **a, char **argv)
{
    int i;
    long value;
    t_stack *node;

    i = 1;
    while (argv[i])
    {
        value = atol(argv[i]);
        if (value < INT_MIN || value > INT_MAX)
            return (0);
        node = new_node((int)value);
        if (!node)
            return (0);
        node->next = *a;
        *a = node;
        i++;
    }
    return (1);
} 

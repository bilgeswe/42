/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:00:00 bakpulat             #+#    #+#             */
/*   Updated: 2024/02/07 12:00:00 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    if (!parse_args(&a, argv))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    b = NULL;
    sort_stack(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
} 
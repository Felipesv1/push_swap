/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:31:38 by felperei          #+#    #+#             */
/*   Updated: 2024/01/31 13:36:09 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack_a)
{
    int first;
    int second;
    int third;
    first = stack_a->head->value;
    second = stack_a->head->next->value;
    third = stack_a->head->next->next->value;

    if ((first > second && second > third && third < first) 
    || (first < second && second > third && third > first)
    ||(first > second && second < third && third > first))
        sa(stack_a);
    
    first = stack_a->head->value;
    second = stack_a->head->next->value;
    third = stack_a->head->next->next->value;

    if (first > second && second < third && third < first)
        ra(stack_a);
    if (first < second && second > third && second < third)
        rra(stack_a);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:49:27 by feliperei         #+#    #+#             */
/*   Updated: 2024/02/02 13:50:55 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_stack(t_stack *list)
{
    t_node *node = list->head;
    t_node *tmp;
    while (node)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    free(list);
}

int is_sorted(t_stack *list)
{
    t_node *node = list->head;
    
    while (node->next != NULL)
    {
        if (node->value > node->next->value)
            return 0;
        node = node->next;
    }
    return 1;
}

int    check_dup(t_stack *list)
{
    t_node *current = list->head;
    t_node *runner;

    while (current != NULL)
    {
        runner = current;
        while (runner->next != NULL)
        {
            if (current->value == runner->next->value)
                return 1;
            runner = runner->next;
        }
        current = current->next;
    }
    return 0;
}


int overflow(t_stack *list)
{
    t_node *node = list->head;
    while (node)
    {
        if (node->value >= 2147483648 )
            return 1;
        node = node->next; 
    }
    return (0);
}

int check_args(t_stack *list)
{
    if (check_dup(list) == 1)
    {
        free_stack(list);
        return (1);
    }
    if (overflow(list) == 1)
        {
            free_stack(list);
            return (1);
        }
}

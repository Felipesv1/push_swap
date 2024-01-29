/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:15:05 by felperei          #+#    #+#             */
/*   Updated: 2024/01/29 14:59:14 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *stack_a)
{
    
    t_node *node1 = stack_a->head;
    t_node *node2 = node1->next;
    t_node *tmp = (t_node *)malloc(sizeof(t_node));
    if (!node1 || !node2)
        return;
    tmp->value = node1->value;
    node1->value = node2->value;
    node2->value = tmp->value;
    free(tmp);
    ft_printf("sa\n");
}



void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node *node_a1 = stack_a->head;
    t_node *node_b1 = stack_b->head;
    t_node *tmp  = node_b1;
    node_b1 = node_b1->next;
    stack_b->head = node_b1;

    if (node_a1 == NULL)
        {
            node_a1 = tmp;
            node_a1->next = NULL;
            stack_a->head = node_a1; 
        }
        else{
                tmp->next = node_a1;
                stack_a->head = tmp;
        }
        stack_b->size--;
        stack_a->size++;
    ft_printf("pa\n");
}

void ra(t_stack *stack_a)
{
    t_node *node_lst;
    t_node *node1;

    node1 = stack_a->head;
    node_lst = stack_a->tail;
    stack_a->head = node1->next;
    node1->next = NULL;
    node_lst->next = node1;
    ft_printf("ra\n");
}

void rra(t_stack *stack_a)
{
    t_node *node_lst = stack_a->tail;
    t_node *node1 = stack_a->head;
    t_node *node_penultimate;
    while (node1 && node1->next->next != NULL)
        node1 = node1->next;
    node_penultimate = node1;
    node1 = stack_a->head;
    node_lst->next = node1;
    node_penultimate->next = NULL;
    stack_a->head = node_lst;
    ft_printf("rra\n");
}
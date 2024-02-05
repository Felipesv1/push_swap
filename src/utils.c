/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:40:10 by feliperei         #+#    #+#             */
/*   Updated: 2024/02/05 15:44:28 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void initial_Stack(t_stack *p)
{
    if (p == NULL)
    {
        free_stack(p);
        return; 
    }
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
}
void print_stack(t_stack *p){
    t_node *ptr = p->head;
    if (ptr == NULL){
        return;
    }
    while(ptr)
    {
        ft_printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
}

long    ft_atol(const char *nptr)
{
    long    res;
    int        sign;

    res = 0;
    sign = 1;
    while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
        nptr++;
    if (*nptr == '-' || *nptr == '+')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9')
    {
        res *= 10;
        res += *nptr++ - '0';
    }
    return ((long)(res * sign));
}

 void add_node_to_top(int n, t_stack *p)
{
    t_node *new_node = (t_node*)malloc(sizeof(t_node));

    if (new_node == NULL)
    {
        free_stack(p);
        return;
    }

    new_node->value = n;

    if (p->head == NULL)
    {
        p->head = new_node;
        p->tail = new_node;

        new_node->next = NULL;
    }
    else
    {
        new_node->next = p->head;
        p->head = new_node;
    }
}

void add_node_to_bottom(int n, t_stack *p)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));

    if (new_node == NULL)
        return;
        
    new_node->value = n;
    if (p->head == NULL)
    {
        p->head = new_node;
        p->tail = new_node;
        new_node->next = NULL;
    }
    else
    {
        p->tail->next = new_node;
        p->tail = new_node;
        new_node->next = NULL;
    }
    p->size++;
}


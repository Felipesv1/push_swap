/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:10 by felperei          #+#    #+#             */
/*   Updated: 2024/01/31 13:32:47 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void inicializaPilha(t_stack *p)
{
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
}
 void add_node_to_bottom(int n, t_stack *p)
{
    t_node *new_node = (t_node*)malloc(sizeof(t_node));

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
 void add_node_to_top(int n, t_stack *p)
{
    t_node *new_node = (t_node*)malloc(sizeof(t_node));

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
        new_node->next = p->head;
        p->head = new_node;
    }
}
void imprimirPilha(t_stack *p){
    t_node *ptr = p->head;
    if (ptr == NULL){
        return;
    }
    else{
        while(ptr)
        {
            ft_printf("%d\n", ptr->value);
            ptr = ptr->next;
        }
    }
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
    if (is_sorted(list) == 1)
        return 1;
    if (check_dup(list) == 1)
        return 1;
    if (overflow(list) == 1)
        return (1);
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

int main(int ac, char **av)
{
    t_stack *a = (t_stack *)malloc(sizeof(t_stack));
    t_stack *b = (t_stack *)malloc(sizeof(t_stack));

    inicializaPilha(a);
    inicializaPilha(b);
    int x;
    int i;

    x = 1;
    if (ac >= 2)
    {
       while (av[x])
            {
                i = 0;
                while (av[x][i])
                {
                    if (!ft_isdigit(av[x][i]))
                        return 1;
                    i++;
                }
            add_node_to_bottom(ft_atol(av[x]), a);
            x++;
            }
        if (check_args(a))
            return 1;
        ft_printf("output antes da operação\n");
        ft_printf("pilha a\t\t\n");

        imprimirPilha(a);
        ft_printf("pilha b\t\t\n");

        imprimirPilha(b);
        ft_printf("output depois da operação\n");
        
        ft_printf("pilha a\t\t\n");
        imprimirPilha(a);
        ft_printf("pilha b\t\t\n");
        imprimirPilha(b);
    }  
    ft_printf("\n");
}

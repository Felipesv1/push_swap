/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:40:10 by feliperei         #+#    #+#             */
/*   Updated: 2024/02/15 11:55:24 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(void **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}
void init_Stack(t_stack *p, int ac , char **av)
{
    t_node *new;
    char **args;
    int i;
    if (ac == 2)
            ft_split(av[1], ' ');
    else 
    {
        i = 1;
        args = av;
    }
    while (args[i])
    {
        new = add_node_to_bottom(ft_atol(args[i]), p);
        if (new == NULL)
        {
            free_stack(p);
            return;
        }
        i++;
    }
    set_index(p);
    if (ac == 2)
        ft_free((void **)args);
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

t_node *add_node_to_bottom(int n, t_stack *p)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));

    if (new_node == NULL)
        return NULL;
        
    new_node->value = n;
    if (p->head == NULL)
    {
        p->head = new_node;
        p->tail = new_node;
        new_node->next = NULL;
        new_node->index = -1;
    }
    else
    {
        p->tail->next = new_node;
        p->tail = new_node;
        new_node->next = NULL;
        new_node->index = -1;
    }
    p->size++;

    return (new_node);
}


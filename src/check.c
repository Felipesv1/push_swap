/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:49:27 by feliperei         #+#    #+#             */
/*   Updated: 2024/02/15 12:51:55 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_stack(t_stack *list)
{
    if (list == NULL)
        return;
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
    return (1);
}
int	has_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}
static int	has_num(char *num)
{
	int	i;
	i = 0;
	while (num[i])
	{
		if (ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
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
                return (1);
            runner = runner->next;
        }
        current = current->next;
    }
    return (0);
}
static	void	check(long tmp, char **args, int i)
{
	if (has_duplicate(tmp, args, i))
		    ft_printf("Error\n");
    if (!has_num(args[i]))
            ft_printf("Error\n");
	if (tmp < -2147483648 || tmp > 2147483647)
		    ft_printf("Error\n");
}
void check_args(char **av, int ac)
{
    long tmp;
    char **args;
    int i;
    int x;

    if(ac == 2)
    {
        exit(-1);
    }
    if (ac == 2)
            args = ft_split(av[1], ' ');
    else 
    {
        i = 0;
        x = 1;
        args = av;
    }
    while (args[x])
    { 
          i = 0;
        while (args[x][i])
        {
        tmp = ft_atol(args[i]);
        check(tmp, args, i);
        i++;
     }
     x++;
    }
    if (ac == 2)
        ft_free((void **)args);
}



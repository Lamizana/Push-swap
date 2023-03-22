/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:51:08 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/25 14:00:47 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* 
 * - Creer un index pour normalisez les nombres.
 * - Push_b sauf la derniere valeur.
 * - Remet dans A trier par l index.
 * - Utilise des rotates ou reverse pour aller chercher la valeur suivante
 *
 * */

static int	value_min(t_list **stack)
{
	int		i;
	t_list	*tmp;

	if (!*stack)
		return (0);
	tmp = (*stack);
	i = 2147483647;
	while (tmp != NULL)
	{
		if (tmp->value < i && tmp->index == -1)
			i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}

static void	ft_normalize(t_list **stack)
{
	t_list	*tmp;
	int		i;
	int		nb_min;

	if (!*stack)
		return ;
	i = 1;
	while (i <= ft_lstsize(*stack))
	{
		tmp = *stack;
		nb_min = value_min(stack);
		while (nb_min != tmp->value)
			tmp = tmp->next;
		tmp->index = i;
		i++;
	}
}

static void	replace_last_value(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->index == ft_lstsize(*stack_a) + (ft_lstsize(*stack_b)))
		rotate_a(stack_a, 0);
	while (ft_lstsize(*stack_a) > 1)
		push_b(stack_a, stack_b);
}

static void	find_last_value(t_list **stack_a, t_list **stack_b)
{
	int	len;

	if (!*stack_a)
		return ;
	len = ft_lstsize(*stack_a);
	while (stack_a != NULL)
	{
		if ((*stack_a)->index == len)
			break ;
		push_b(stack_a, stack_b);
	}
	replace_last_value(stack_a, stack_b);
}

static void	insert_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = (*stack_a)->index -1;
	tmp = (*stack_b);
	while (i != 0)
	{
		tmp = (*stack_b);
		j = 0;
		while ((tmp)->index != i)
		{
			tmp = tmp->next;
			j++;
		}
		if (j > i / 2)
			while ((*stack_b)->index != i)
				reverse_b(stack_b, 0);
		else
			while ((*stack_b)->index != i)
				rotate_b(stack_b, 0);
		push_a(stack_a, stack_b);
		i = i - 1;
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	(*stack_b) = NULL;
	ft_normalize(stack_a);
	find_last_value(stack_a, stack_b);
	insert_sort(stack_a, stack_b);
}

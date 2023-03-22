/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zehd_sort_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:18:07 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/22 14:27:29 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_stack_b(t_list **stack_a, t_list **stack_b);
static int	ft_lstlast(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack->value);
}

static void	ft_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	n;
	int	b;

	n = ft_lstlast(*stack_a);
	b = ft_lstlast(*stack_b);
	while (ft_sort_a(*stack_a) != 0)
	{
		if ((ft_lstsize(*stack_a) >= 2)
				&& (n < (*stack_a)->value) && n < (*stack_a)->next->value)
		{
			reverse_a(stack_a, 0);
			n = ft_lstlast(*stack_a);
		}
		else if ((*stack_a)->value < (*stack_a)->next->value)
			push_b(stack_a, stack_b);
		else if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a, 0);
	}
}

static void	ft_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	n;
	int	b;

	n = ft_lstlast(*stack_a);
	b = ft_lstlast(*stack_b);
	while (ft_sort_b(*stack_b) != 0)
	{
		if (((*stack_a)->value > n)
			&& ((ft_lstsize(*stack_b) >= 2)
			&& ((*stack_b)->value < b)))
			rotates(stack_a, stack_b);

		else if (((*stack_b)->next != NULL && (*stack_a)->next != NULL)
			&& ((*stack_b)->value < (*stack_b)->next->value)
			&& ((*stack_a)->value > (*stack_a)->next->value))
			swaps(stack_a, stack_b);
		
		else if (((*stack_b)->next != NULL)
			&& ((*stack_b)->value < (*stack_b)->next->value))
			swap_b(stack_b, 0);
		push_a(stack_a, stack_b);
/*
		if (((*stack_b)->next != NULL && (*stack_a)->next != NULL)
			&& ((*stack_b)->value < (*stack_b)->next->value)
			&& ((*stack_a)->value > (*stack_a)->next->value))
			swaps(stack_a, stack_b);
		else if (((*stack_b)->next != NULL)
			&& ((*stack_b)->value < (*stack_b)->next->value))
			swap_b(stack_b, 0);
		else if (((*stack_a)->value > n)
			&& ((ft_lstsize(*stack_b) >= 2)
				&& ((*stack_b)->value < b)))
		{
			rotates(stack_a, stack_b);
			b = ft_lstlast(*stack_b);
			n = ft_lstlast(*stack_a);
		}
		else if ((ft_lstsize(*stack_b) >= 2)
				&& ((*stack_b)->value < b))
		{
			rotate_b(stack_b, 0);
		}

		else if (((*stack_a)->value > (*stack_a)->next->value)
				&& ((*stack_a)->value > n))
		{
			rotate_a(stack_a, 0);
		}
		*/
	}
}

static void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	if (ft_sort_a(*stack_a) == 0 && ft_sort_b(*stack_b) == 0)
	{
		while (*stack_b != NULL)
			push_a(stack_a, stack_b);
	}
}

// Pour 10 --> 60
// Pour 100 --> 2 100
// Pour 1000 --> 35 000
void	zehd_sort_v2(t_list **stack_a, t_list **stack_b)
{
	// Appliquer des rotates , reverses et swaps pour optimiser:
	while (ft_sort_a(*stack_a) != 0)
	{
		ft_stack_a(stack_a, stack_b);
		ft_stack_b(stack_a, stack_b);
		ft_push_a(stack_a, stack_b);
	}
}

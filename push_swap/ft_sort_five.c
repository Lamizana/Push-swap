/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:39:29 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/24 08:01:28 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	n;

	n = ft_lstlast(*stack_a);
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

void	ft_stack_b(t_list **stack_a, t_list **stack_b)
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
	}
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	if (ft_sort_a(*stack_a) == 0 && ft_sort_b(*stack_b) == 0)
	{
		while (*stack_b != NULL)
			push_a(stack_a, stack_b);
	}
}

void	ft_particular_case(t_list **stack_a, t_list **stack_b)
{
	if (((*stack_a)->value > (*stack_a)->next->value)
		&& ((*stack_a)->value > (*stack_a)->next->next->value)
		&& ((*stack_a)->value > (*stack_a)->next->next->next->value)
		&& ((*stack_a)->value > ft_lstlast(*stack_a))
		&& ((*stack_a)->next->value < (*stack_a)->value)
		&& ((*stack_a)->next->value > (*stack_a)->next->next->value)
		&& ((*stack_a)->next->value < ft_lstlast(*stack_a))
		&& (ft_lstlast(*stack_a) < (*stack_a)->value)
		&& (ft_lstlast(*stack_a) > (*stack_a)->next->value)
		&& (ft_lstlast(*stack_a) > (*stack_a)->next->next->value)
		&& (ft_lstlast(*stack_a) > (*stack_a)->next->next->next->value))
	{
		rotate_a(stack_a, 0);
		swap_a(stack_a, 0);
		push_b(stack_a, stack_b);
		swap_a(stack_a, 0);
		push_a(stack_a, stack_b);
		swap_a(stack_a, 0);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) <= 5)
	{
		ft_particular_case(stack_a, stack_b);
		while (ft_sort_a(*stack_a) != 0)
		{
			ft_stack_a(stack_a, stack_b);
			ft_stack_b(stack_a, stack_b);
			ft_push_a(stack_a, stack_b);
		}
	}
}	

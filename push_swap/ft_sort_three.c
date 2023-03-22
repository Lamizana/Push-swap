/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:38:19 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/26 09:33:37 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_three_utils(t_list **stack, int flag)
{
	swap_a(stack, 0);
	if (flag == 0)
		reverse_a(stack, 0);
	else
		rotate_a(stack, 0);
}

void	ft_sort_loop(t_list **stack_a)
{
	if (((*stack_a)->value > (*stack_a)->next->value)
		&& ((*stack_a)->value < (*stack_a)->next->next->value))
		swap_a(stack_a, 0);
	else if (((*stack_a)->value > (*stack_a)->next->value)
		&& ((*stack_a)->value > (*stack_a)->next->next->value)
		&& ((*stack_a)->next->value > (*stack_a)->next->next->value))
		ft_sort_three_utils(stack_a, 0);
	else if (((*stack_a)->next->value < (*stack_a)->value)
		&& ((*stack_a)->next->value < (*stack_a)->next->next->value)
		&& ((*stack_a)->value > (*stack_a)->next->next->value))
		rotate_a(stack_a, 0);
	else if (((*stack_a)->value < (*stack_a)->next->value)
		&& ((*stack_a)->value < (*stack_a)->next->next->value)
		&& ((*stack_a)->next->value > (*stack_a)->next->next->value))
		ft_sort_three_utils(stack_a, 1);
	else if (((*stack_a)->value < (*stack_a)->next->value)
		&& ((*stack_a)->value > (*stack_a)->next->next->value))
		reverse_a(stack_a, 0);
}

void	sort_three(t_list **stack_a)
{
	int	flag;

	flag = 0;
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a, 0);
	}
	else if (ft_lstsize(*stack_a) == 3)
	{
		while (ft_sort_a(*stack_a) != 0)
			ft_sort_loop(stack_a);
	}
}

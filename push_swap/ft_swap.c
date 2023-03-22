/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:05:59 by alamizan          #+#    #+#             */
/*   Updated: 2022/12/15 10:42:14 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_a(t_list **stack_a, int flag)
{
	int	tmp_value;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp_value = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp_value;
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b, int flag)
{
	int	tmp_value;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp_value = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tmp_value;
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	swaps(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	write(1, "ss\n", 3);
}

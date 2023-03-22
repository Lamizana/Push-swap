/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:43:16 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/25 10:21:41 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	int	value;
	int	index;

	if (*stack_b == NULL)
		return ;
	index = (*stack_b)->index;
	value = ft_lstdel(stack_b);
	ft_lstpush(stack_a, value);
	(*stack_a)->index = index;
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	int	value;
	int	index;

	if (*stack_a == NULL)
		return ;
	index = (*stack_a)->index;
	value = ft_lstdel(stack_a);
	ft_lstpush(stack_b, value);
	(*stack_b)->index = index;
	write(1, "pb\n", 3);
}

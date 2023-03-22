/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:09:05 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/26 09:21:00 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_list **stack_a, int flag)
{
	int		value;
	int		index;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	index = (*stack_a)->index;
	value = ft_lstdel(stack_a);
	ft_lstadd_back(stack_a, ft_lstnew(value, index));
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b, int flag)
{
	int		value;
	int		index;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	index = (*stack_b)->index;
	value = ft_lstdel(stack_b);
	ft_lstadd_back(stack_b, ft_lstnew(value, index));
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rotates(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:47:11 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/26 11:19:51 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	value_min(t_list **stack)
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

void	ft_normalize(t_list **stack)
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

int	len_bit(int size)
{
	int	len;
	int	i;

	len = 1;
	i = 0;
	while (size / len != 0)
	{
		len *= 2;
		i++;
	}
	return (i);
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	int	len;
	int	size;
	int	i;
	int	j;

	i = 0;
	ft_normalize(stack_a);
	len = len_bit(ft_lstsize(*stack_a));
	while (i < len)
	{
		j = 0;
		size = ft_lstsize(*stack_a);
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				rotate_a(stack_a, 0);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b != NULL)
			push_a(stack_a, stack_b);
		i++;
	}
}

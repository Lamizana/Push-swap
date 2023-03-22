/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:06:06 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/26 09:12:16 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_sort_a(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (1);
		else
			stack = stack->next;
	}
	return (0);
}

int	ft_sort_b(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			return (1);
		else
			stack = stack->next;
	}
	return (0);
}

int	ft_lstlast(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack->value);
}

int	ft_lstsize(t_list *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

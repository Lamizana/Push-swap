/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:00:05 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/25 11:43:47 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_lstdel_back(t_list **stack)
{
	t_list	*tmp;
	t_list	*p_tmp;

	if (!*stack)
		return ;
	if ((*stack)->next == NULL)
	{
		free(*stack);
		return ;
	}
	tmp = *stack;
	p_tmp = *stack;
	while (tmp->next != NULL)
	{
		p_tmp = tmp;
		tmp = p_tmp->next;
	}
	p_tmp->next = NULL;
	free(tmp);
}

void	reverse_a(t_list **stack_a, int flag)
{
	t_list	*p_tmp;
	int		value;
	int		index;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	p_tmp = *stack_a;
	while (p_tmp->next != NULL)
		p_tmp = p_tmp->next;
	value = p_tmp->value;
	index = p_tmp->index;
	ft_lstdel_back(stack_a);
	ft_lstpush(stack_a, value);
	(*stack_a)->index = index;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	reverse_b(t_list **stack_b, int flag)
{
	t_list	*p_tmp;
	int		value;
	int		index;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	p_tmp = *stack_b;
	while (p_tmp->next != NULL)
		p_tmp = p_tmp->next;
	value = p_tmp->value;
	index = p_tmp->index;
	ft_lstdel_back(stack_b);
	ft_lstpush(stack_b, value);
	(*stack_b)->index = index;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	reverses(t_list **stack_a, t_list **stack_b)
{
	reverse_a(stack_a, 1);
	reverse_b(stack_b, 1);
	write(1, "rrr\n", 4);
}

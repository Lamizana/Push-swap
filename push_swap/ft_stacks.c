/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:16:31 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/25 12:19:33 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*ft_lstnew(int value, int index)
{
	t_list	*p_new;

	p_new = malloc(sizeof(t_list));
	if (p_new == NULL)
		return (0);
	p_new->value = value;
	p_new->index = index;
	p_new->next = NULL;
	return (p_new);
}

void	ft_lstadd_back(t_list **stack, t_list *lstnew)
{
	t_list	*p_tmp;

	if (!lstnew || !stack)
		return ;
	if (*stack == NULL)
	{
		*stack = lstnew;
		return ;
	}
	p_tmp = *stack;
	while (p_tmp->next)
		p_tmp = p_tmp->next;
	p_tmp->next = lstnew;
}

void	ft_lstpush(t_list **stack, int value)
{
	t_list	*p_new;

	p_new = malloc(sizeof(t_list));
	if (p_new != NULL)
	{
		p_new->value = value;
		p_new->next = *stack;
		*stack = p_new;
	}
	else
		return ;
}

int	ft_lstdel(t_list **stack)
{
	t_list	*stack_tmp;
	int		value;

	value = -1;
	if (stack != NULL)
	{
		stack_tmp = (*stack)->next;
		value = (*stack)->value;
		free(*stack);
		*stack = NULL;
		*stack = stack_tmp;
	}
	return (value);
}

void	ft_lstclear(t_list **stack)
{
	t_list	*p_tmp;
	t_list	*p_tmp_next;

	if (stack == NULL)
		return ;
	p_tmp = (*stack);
	while (p_tmp != NULL)
	{
		p_tmp_next = p_tmp->next;
		free(p_tmp);
		p_tmp = p_tmp_next;
	}
	(*stack) = NULL;
}

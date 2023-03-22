/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zehd_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:38:25 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/03 17:30:54 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	zehd_sort_v1(t_list **stack_a, t_list **stack_b)
{
	int	trie_a;
	int	trie_b;

	trie_a = ft_sort_a(*stack_a);
	trie_b = 0;
	if (trie_a == 0)
		return ;
	trie_a = ft_sort_a(*stack_a);
	while (trie_a != 0 || trie_b != 0)
	{
		while (trie_a != 0)
		{
			if ((ft_lstsize(*stack_a) >= 2 && ft_lstsize(*stack_b) >= 2)
				&& ((*stack_a)->value > (*stack_a)->next->value)
				&& ((*stack_b)->value < (*stack_b)->next->value))
				swaps(stack_a, stack_b);
			else if ((*stack_a)->value > (*stack_a)->next->value)
				swap_a(stack_a, 0);
			else if ((*stack_a)->value < (*stack_a)->next->value)
				push_b(stack_a, stack_b);
			else if (((*stack_a)->value > (*stack_a)->next->value)
				&& ((*stack_b)->value > (*stack_b)->next->value))
				rotates(stack_a, stack_b);
			else if (((*stack_a)->value < (*stack_a)->next->value)
				&& ((*stack_b)->value > (*stack_b)->next->value))
				reverses(stack_a, stack_b);
			trie_a = ft_sort_a(*stack_a);
		}
		// Si A est trier et qu il ya rien dans B:
		if (trie_a == 0 && !*stack_b)
			return ;
		trie_b = ft_sort_b(*stack_b);
		while (trie_b != 0)
		{
			if ((ft_lstsize(*stack_a) >= 2 && ft_lstsize(*stack_b) >= 2)
				&& ((*stack_a)->value > (*stack_a)->next->value)
				&& ((*stack_b)->value < (*stack_b)->next->value))
				swaps(stack_a, stack_b);
			else if ((*stack_b)->value < (*stack_b)->next->value)
				swap_b(stack_b, 0);
			else if ((*stack_b)->value > (*stack_b)->next->value)
				push_a(stack_a, stack_b);
			trie_b = ft_sort_b(*stack_b);
		}
		// Gere le cas de 1 element dans b:
		if ((*stack_b)->next == NULL)
			push_a(stack_a, stack_b);
		// Gestion des 1er nombres dans a et b;
		else if ((*stack_b)->value > (*stack_b)->next->value)
			push_a(stack_a, stack_b);
		trie_a = ft_sort_a(*stack_a);
		trie_b = ft_sort_b(*stack_b);
	}
	if (ft_sort_a(*stack_a) == 0 && ft_sort_b(*stack_b) == 0)
	{
		while (*stack_b != NULL)
			push_a(stack_a, stack_b);
	}
}

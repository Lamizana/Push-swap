/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:39:17 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/25 07:49:36 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* - Choisir un pivot.
 * - si A1 < pivot -> push_b.
 * - si A1 > pivot -> rotate.
 *
 * - une fois a avec 1 element.
 * - push_a.     
 * - recommencer l operation.
 */
static void tour_1(t_list **stack_a, t_list **stack_b)
{
	int nb_a;
	int nb_b;

	nb_a = ft_lstlast(*stack_a);
	nb_b = ft_lstlast(*stack_b);
	while ((*stack_a)->value != nb_a)
	{

		if ((ft_lstsize(*stack_b) >= 2 && ft_lstsize(*stack_b) >= 2)
			&& ((*stack_b)->value < (*stack_b)->next->value)
			&& ((*stack_a)->value > (*stack_a)->next->value))
			swaps(stack_a, stack_b);
		else if (((*stack_a)->value > nb_a)
			&& ((ft_lstsize(*stack_b) >= 2)
				&& ((*stack_b)->value < nb_b)))
			rotates(stack_a, stack_b);
		else if (ft_lstlast(*stack_a) < (*stack_a)->value
				&& ft_lstlast(*stack_a) < (*stack_a)->next->value
				&& ft_lstlast(*stack_b) > (*stack_b)->next->value
				&& ft_lstlast(*stack_b) < (*stack_b)->next->value)
			reverses(stack_a, stack_b);

		else if ((*stack_a)->value < nb_a)
		{
			push_b(stack_a, stack_b);
			if ((*stack_b)->value < (*stack_b)->next->value
				&& ft_lstsize(*stack_b) >= 2)
				swap_b(stack_b, 0);
		}
		else if ((*stack_a)->value > nb_a)
			rotate_a(stack_a, 0);
		else if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a, 0);
		else if ((*stack_a)->value < (*stack_a)->next->value)
			push_b(stack_a, stack_b);
		/*
		//else if ((*stack_a)->value < nb_a)
		//	push_b(stack_a, stack_b);
		else if ((*stack_a)->value > (*stack_a)->next->value)
			rotate_a(stack_a, 0);
		else if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a, 0);
		else if ((ft_lstsize(*stack_b) >= 2)
			&& ((*stack_b)->value < (*stack_b)->next->value))
			swap_b(stack_b, 0);
*/

		if (ft_sort_a(*stack_a) == 0)
			break;
	}
	while ((*stack_b)->next != NULL)
	{
		if ((ft_lstsize(*stack_b) >= 2 && ft_lstsize(*stack_b) >= 2)
			&& ((*stack_b)->value < (*stack_b)->next->value)
			&& ((*stack_a)->value > (*stack_a)->next->value))
			swaps(stack_a, stack_b);


		else if (((*stack_a)->value > ft_lstlast(*stack_a))
			&& ((ft_lstsize(*stack_b) >= 2)
			&& ((*stack_b)->value < ft_lstlast(*stack_b))))
			rotates(stack_a, stack_b);
	
		else if (ft_lstlast(*stack_a) < (*stack_a)->value
				&& ft_lstlast(*stack_a) < (*stack_a)->next->value
				&& ft_lstlast(*stack_b) > (*stack_b)->next->value
				&& ft_lstlast(*stack_b) < (*stack_b)->next->value)
			reverses(stack_a, stack_b);

		else if ((*stack_b)->value > (*stack_b)->next->value)
			push_a(stack_a, stack_b);
		else if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a, 0);
		else if ((*stack_b)->value < (*stack_b)->next->value)
			swap_b(stack_b, 0);
		if (ft_sort_b(*stack_b) == 0)
			break;
	}
}

void	sort_big_1(t_list **stack_a, t_list **stack_b)
{
	while (ft_sort_a(*stack_a) != 0 || ft_sort_b(*stack_b) != 0)
	{
		tour_1(stack_a, stack_b);
		ft_push_a(stack_a, stack_b);
	}
	//ft_display(stack_a, 'A');
	//ft_display(stack_b, 'B');
}

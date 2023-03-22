/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:45:24 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/26 11:20:53 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		exit (0);
	stack_a = NULL;
	stack_b = NULL;
	check_numbers(argc, argv);
	init_stack(argc, argv, &stack_a);
	sort_three(&stack_a);
	sort_five(&stack_a, &stack_b);
	if (ft_lstsize(stack_a) > 5 && ft_sort_a(stack_a) != 0)
		radix(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}

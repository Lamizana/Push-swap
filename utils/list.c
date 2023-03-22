/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:33:09 by alamizan          #+#    #+#             */
/*   Updated: 2022/12/03 14:49:19 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

typedef struct pile
{
	int			donnee;
	struct pile	*precedent;
}t_pile;

void	pile_push(t_pile **stack, int donnee);
int		pile_pop(t_pile **stack);
void	init_stack_a(int argc, char *argv[], t_pile **stack_a);
void	swap_a(int *nb_a, t_pile **stack_a, int *nb_b, t_pile **stack_b);
void	affichage_stack(int nb_a, t_pile *stack_a, int nb_b, t_pile *stack_b);

int	main(int argc, char *argv[])
{
	t_pile	*stack_a;
	t_pile	*stack_b;
	int		nb_element;
	int		nb_element_b;

	nb_element_b = 0;
	nb_element = argc - 1;

	init_stack_a(argc, argv, &stack_a);

	affichage_stack(nb_element, stack_a, nb_element_b, stack_b);
	swap_a(&nb_element, &stack_a, &nb_element_b, &stack_b);
	
	affichage_stack(nb_element, stack_a, nb_element_b, stack_b);
	return (0);
}

// ------------------------------------------------------------------
// - FONCTIONS -
// ------------------------------------------------------------------
void	pile_push(t_pile **stack, int donnee)
{
	t_pile	*p_new;

	p_new = malloc(sizeof * p_new);
	if (p_new != NULL)
	{
		p_new->donnee = donnee;
		p_new->precedent = *stack;
		*stack = p_new;
	}
	else
		exit (EXIT_FAILURE);
}

// ------------------------------------------------------------------
void	init_stack_a(int argc, char *argv[], t_pile **stack_a)
{
	int	index;
	int	i;

	i = 1;
	index = 0;
	if (argc > 1)
	{
		while (index < argc -1)
		{
			pile_push(stack_a, atoi(argv[i]));
			index++;
			i++;
		}
	}
}

// ------------------------------------------------------------------
int	pile_pop(t_pile **stack)
{
	t_pile	*stack_tmp;
	int		donnee_retire;		

	donnee_retire = -1;
	if (stack != NULL)
	{
		stack_tmp = (*stack)->precedent;
		donnee_retire = (*stack)->donnee;
		free(*stack);
		*stack = NULL;
		*stack = stack_tmp;
	}
	return (donnee_retire);
}

// ------------------------------------------------------------------
void	swap_a(int *nb_a, t_pile **stack_a, int *nb_b, t_pile **stack_b)
{
	int	donnee;

	if (*nb_a <= 1)
		return ;
	donnee = pile_pop(stack_a);
	pile_push(stack_b, donnee);
	*nb_a -= 1;
	*nb_b += 1;
}

// ------------------------------------------------------------------
void	affichage_stack(int nb_a, t_pile *stack_a, int nb_b, t_pile *stack_b)
{
	printf("----------------------------------------\n");
	while (nb_a > 0)
	{
		if (nb_b > 0)
		{
			printf("%d   %d\n", stack_a->donnee, stack_b->donnee);
			stack_b = stack_b->precedent;
			nb_b--;
		}
		else
			printf("%d\n", stack_a->donnee);
		stack_a = stack_a->precedent;
		nb_a--;
	}
	printf("_   _\n");
	printf("a   b\n");
}

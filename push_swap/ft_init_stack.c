/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 08:02:54 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/26 09:03:46 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_init_str(t_list **stack, char **tab)
{
	long int	n;
	int			i;
	int			flag;

	flag = 0;
	i = 1;
	while (tab[i])
	{
		n = ft_atoi(tab[i], &flag);
		ft_doublon(stack, n, tab);
		ft_lstadd_back(stack, ft_lstnew(n, -1));
		check_int(tab, stack, &flag);
		i++;
	}
}

static void	ft_init_stack(int argc, char *argv[], t_list **stack)
{
	long int	n;
	int			i;
	int			flag;
	int			index;

	index = 1;
	flag = 0;
	i = 2;
	while (index < argc - 1)
	{
		n = ft_atoi(argv[i], &flag);
		ft_doublon_stack(stack, n);
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(argv[i], &flag), -1));
		check_stack(stack, &flag);
		index++;
		i++;
	}
}

t_list	*init_str(int argc, char *argv[], t_list **stack)
{
	char		**tab;
	int			flag;

	flag = 0;
	tab = NULL;
	if (argc == 2)
	{
		check_empty_str(argc, argv);
		tab = check_split(tab, argv);
		*stack = ft_lstnew(ft_atoi(tab[0], &flag), -1);
		check_int(tab, stack, &flag);
		ft_init_str(stack, tab);
		check_tab(tab);
		return (*stack);
	}
	return (NULL);
}

t_list	*init_stack(int argc, char *argv[], t_list **stack)
{
	int		flag;

	flag = 0;
	if (argc > 1)
	{
		init_str(argc, argv, stack);
		if (argc > 2)
		{
			check_empty_str(argc, argv);
			check_str(argc, argv);
			*stack = ft_lstnew(ft_atoi(argv[1], &flag), -1);
			check_stack(stack, &flag);
			ft_init_stack(argc, argv, stack);
		}
		return (*stack);
	}
	return (NULL);
}

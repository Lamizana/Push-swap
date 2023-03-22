/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:45:41 by alamizan          #+#    #+#             */
/*   Updated: 2022/12/21 13:11:20 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

char	**check_split(char **tab, char *argv[])
{
	tab = ft_split(argv[1]);
	if (!tab)
	{
		free(tab);
		ft_error();
	}
	return (tab);
}

void	check_int(char **tab, t_list **stack, int *flag)
{
	int	i;

	i = 0;
	if (*flag == 1)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		ft_lstclear(stack);
		ft_error();
	}
}

void	check_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	check_stack(t_list **stack, int *flag)
{
	if (*flag == 1)
	{
		ft_lstclear(stack);
		ft_error();
	}
}

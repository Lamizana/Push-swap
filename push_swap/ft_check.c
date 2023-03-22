/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:14:41 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/26 09:36:50 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_numbers(int argc, char *argv[])
{
	int	j;
	int	i;

	j = 1;
	while (j < argc)
	{
		if (argv[j][0] == '\0')
			ft_error();
		i = 0;
		while (argv[j][i] != '\0')
		{
			if ((argv[j][i] >= '0' && argv[j][i] <= '9') ||
				(argv[j][i] == ' ' || argv[j][i] == '\t'))
				i++;
			else if ((argv[j][i] == '-' || argv[j][i] == '+') &&
					(argv[j][i + 1] >= '0' && argv[j][i + 1] <= '9') &&
					(argv[j][i - 1] < '0' || argv[j][i - 1] > '9'))
				i++;
			else
				ft_error();
		}
		j++;
	}
}

void	check_empty_str(int argc, char *argv[])
{
	int	index;
	int	i;
	int	len;

	index = 1;
	while (index < argc)
	{
		i = 0;
		len = 0;
		while (argv[index][i] != '\0')
		{
			while ((argv[index][i] == ' ' || argv[index][i] == '\t'))
			{
				len++;
				i++;
			}
			if (argv[index][i] != '\0')
				i++;
		}
		if (len == ft_strlen(argv[index]))
			ft_error();
		index++;
	}
}

void	check_str(int argc, char *argv[])
{
	int	index;
	int	i;

	index = 1;
	while (index < argc - 1)
	{
		i = 0;
		while (argv[index][i] != '\0')
		{
			while (argv[index][i] == ' ')
				i++;
			while (argv[index][i] >= '0' && argv[index][i] <= '9')
				i++;
			if ((argv[index][i] == ' ')
				&& (argv[index][i + 1] >= '0' && argv[index][i + 1] <= '9'))
				ft_error();
			i++;
		}
		index++;
	}
}

void	ft_doublon(t_list **stack, int n, char **tab)
{
	t_list	*p_tmp;

	p_tmp = *stack;
	while (p_tmp->next)
	{
		if (p_tmp->value == n)
		{
			check_tab(tab);
			ft_lstclear(stack);
			ft_error();
		}
		p_tmp = p_tmp->next;
	}
	if (p_tmp->value == n)
	{
		check_tab(tab);
		ft_lstclear(stack);
		ft_error();
	}
}

void	ft_doublon_stack(t_list **stack, int n)
{
	t_list	*p_tmp;

	p_tmp = *stack;
	while (p_tmp->next)
	{
		if (p_tmp->value == n)
		{
			ft_lstclear(stack);
			ft_error();
		}
		p_tmp = p_tmp->next;
	}
	if (p_tmp->value == n)
	{
		ft_lstclear(stack);
		ft_error();
	}
}

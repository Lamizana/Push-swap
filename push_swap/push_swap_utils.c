/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:58:52 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/26 09:12:23 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_create_number(const char *str, int *signe, long int *number)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		*signe = *signe + 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*number = (*number * 10) + (str[i] - '0');
		i++;
	}
}

int	ft_atoi(const char *str, int *flag)
{
	int			signe;
	long int	number;

	signe = 0;
	number = 0;
	if (!str)
		ft_error();
	ft_create_number(str, &signe, &number);
	if (signe == 1)
		number = number * -1;
	if (number > 2147483647 || number < -2147483648)
	{
		*flag = 1;
		return (0);
	}
	return (number);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

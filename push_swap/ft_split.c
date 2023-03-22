/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:33:32 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/03 13:29:42 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	nb_bloc(char *str)
{
	int	bloc;
	int	i;

	bloc = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] != '\0')
			bloc++;
		while (str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n' && str[i] != '\0')
			i++;
	}
	return (bloc);
}

static void	ft_parsing(int *i, char *str, int *flag)
{
	while ((str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'))
		*i = *i + 1;
	*flag = *i;
}

static void	ft_copy(char **tab, char *str, int *len, int *flag)
{
	static int	j = 0;
	int			k;

	k = 0;
	tab[j] = malloc(sizeof(char) * (*len + 1));
	while (k != *len)
	{
		tab[j][k] = str[*flag];
		k++;
		*flag = *flag +1;
	}
	tab[j][*len] = '\0';
	j = j + 1;
}

char	**ft_split(char *str)
{
	char	**tab;
	int		len;
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (nb_bloc(str) + 1));
	while (str[i] != '\0')
	{
		len = 0;
		ft_parsing(&i, str, &flag);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			i++;
			len++;
		}
		ft_copy(tab, str, &len, &flag);
		ft_parsing(&i, str, &flag);
	}
	tab[nb_bloc(str)] = 0;
	return (tab);
}

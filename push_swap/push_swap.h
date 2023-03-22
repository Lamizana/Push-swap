/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:46:51 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/26 09:47:52 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

/* STRUCTURE */
typedef struct list
{
	int			value;
	int			index;
	struct list	*next;
}t_list;

t_list	*ft_lstnew(int value, int index);
void	ft_lstadd_back(t_list **stack, t_list *lstnew);
void	ft_lstpush(t_list **stack, int value);
void	ft_lstclear(t_list **stack);
int		ft_lstdel(t_list **stack);

t_list	*init_str(int argc, char *argv[], t_list **stack);
t_list	*init_stack(int argc, char *argv[], t_list **stack);

/* PARSING */
void	check_int(char **tab, t_list **stack, int *flag);
void	check_empty_str(int argc, char *argv[]);
void	check_numbers(int argc, char *argv[]);
void	check_str(int argc, char *argv[]);
void	check_tab(char **tab);
void	check_stack(t_list **stack, int *flag);
void	ft_error(void);
void	ft_doublon(t_list **stack, int n, char **tab);
void	ft_doublon_stack(t_list **stack, int n);
char	**check_split(char **tab, char *argv[]);

/* AUTHORIZED INSTRUCTION */
void	swap_a(t_list **stack_a, int flag);
void	swap_b(t_list **stack_b, int flag);
void	swaps(t_list **stack_a, t_list **stack_b);

void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

void	rotate_a(t_list **stack_a, int flag);
void	rotate_b(t_list **stack_b, int flag);
void	rotates(t_list **stack_a, t_list **stack_b);

void	reverse_a(t_list **stack_a, int flag);
void	reverse_b(t_list **stack_b, int flag);
void	reverses(t_list **stack_a, t_list **stack_b);

/* SMALL SORT */
void	sort_three(t_list **stack_a);
void	ft_sort_three_utils(t_list **stack, int flag);
void	ft_sort_loop(t_list **stack_a);

void	sort_five(t_list **stack_a, t_list **stack_b);
void	ft_particular_case(t_list **stack_a, t_list **stack_b);
void	ft_stack_a(t_list **stack_a, t_list **stack_b);
void	ft_stack_b(t_list **stack_a, t_list **stack_b);
void	ft_push_a(t_list **stack_a, t_list **stack_b);

void	radix(t_list **stack_a, t_list **stack_b);
void	ft_normalize(t_list **stack);
int		value_min(t_list **stack);
int		len_bit(int size);

/* SORT UTILS */
int		ft_sort_a(t_list *stack);
int		ft_sort_b(t_list *stack);
int		ft_lstsize(t_list *stack);
int		ft_lstlast(t_list *stack_a);

/* UTILS */
char	**ft_split(char *str);
int		ft_strlen(char *str);
int		ft_atoi(const char *str, int *flag);
#endif

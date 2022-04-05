/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:03:56 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/04/04 14:51:15 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define MAXINT 2147483647
# define MININT -2147483647
# define OK 0

# define SORTED 2
# define RSORTED 4
# define NOT_SORTED 8

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_pms
{
	int		ac;
	int		flag_unpacked;
	int		size_a;
	int		size_b;
	t_node	*begin_a;
	t_node	*begin_b;
	int		*arr;
	char	**av;
}				t_pms;

/*
	init.c
*/
void	ft_init(int argc, char **argv, t_pms *pms);

/*
	check_args.c
*/
int		ft_parse(t_pms *pms, int is_checker);

/*
	utils.c
*/
int		ft_parse_av(t_pms *pms);
int		ft_clean_exit(t_pms *pms);
int		ft_strcmp(const char *str1, const char *str2);
long	ft_atoi(const char *str);
void	ft_insertion_sort(t_pms *pms);

/*
	lst_operations.c
*/
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstnew(int value, int index);

/*
	stack_operations{utils}.c
*/
int		ft_is_stack_sorted(t_pms *pms, char stack, int is_five);
int		ft_find_stack_position(t_pms pms, int index, char stack);
void	ft_index_stack_a(t_pms *pms);
void	ft_cast_operation(int times, t_pms *pms, void (*op)(t_pms*, int));
void	ft_to_the_top(int index, char stack, t_pms *pms);
void	ft_choose_size_lst(t_node **lst, char stack, int *size, t_pms *pms);
void	ft_free_stack(char stack, t_pms *pms);
/*
	ft_split.c
*/
int		ft_get_strnumber(const char *s, char sep);
char	**ft_split(char const *s, char sep);

/*
	ft_butterfly.c, sorting.c
*/
void	ft_butterfly(t_pms *pms);
void	ft_sort_three(t_pms *pms, int is_five);
void	ft_sort(t_pms *pms);

/*
	stack_{push, rotate, reverse, swap}.c
*/
void	pa(t_pms *pms, int print);
void	pb(t_pms *pms, int print);
void	ra(t_pms *pms, int print);
void	rb(t_pms *pms, int print);
void	rr(t_pms *pms, int print);
void	rra(t_pms *pms, int print);
void	rrb(t_pms *pms, int print);
void	rrr(t_pms *pms, int print);
void	sa(t_pms *pms, int print);
void	sb(t_pms *pms, int print);
void	ss(t_pms *pms, int print);

#endif
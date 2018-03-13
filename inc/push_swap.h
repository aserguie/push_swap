/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:18:34 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 12:07:33 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_cdll
{
	int				data;
	int				index;
	int				target;
	int				red;
	int				green;
	struct s_cdll	*next;
	struct s_cdll	*prev;
}				t_cdll;

typedef struct	s_stack
{
	t_cdll		*first;
	t_cdll		*last;
	int			len;
}				t_stack;

typedef struct	s_set
{
	t_stack		sta_a;
	t_stack		sta_b;
	t_stack		inst;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*instru;
	int			color;
	int			target;
	int			aff_instru;
	int			aff_stack;
	int			frequence;
}				t_set;

void			ft_set(t_set *set, t_set *game_set);
void			ft_free_set(t_set *set);
int				ft_index(t_stack **stack);
int				ft_parse_flags(int ac, char **av, t_set **st_a);
int				ft_parse(int ac, char **av, t_set **set);
void			ft_create_node_list(t_stack **stack, int value, int index);
void			ft_create_node_cdll(t_stack **stack_1, t_stack **stack_2);
void			ft_erase_node_cdll(t_stack **stack);
void			ft_add_end_cdll(t_stack **stack, int value, int index);
void			ft_push_back_cdll(t_stack **stack_1, t_stack **stack_2);
void			ft_swap(t_stack **stack);
void			ft_rotate(t_stack **stack);
void			ft_rev_rotate(t_stack **stack);
void			ft_pop_node_cdll(t_stack **st_1, t_stack **st_2);
int				ft_is_numbers(char *str, int ctr);
int				ft_check_commands(char *line, t_stack **st_a, t_stack **st_b);
int				ft_sorted(t_stack **stack_a, t_stack **stack_b);
int				ft_min_max(t_stack **stack_a, t_stack **stack_b, int i);
int				ft_short(t_stack **curr, t_stack **help, t_stack **lst);
int				ft_long(t_stack **st_a, t_stack **st_b, t_stack **lst);
int				ft_merge(t_stack **st_a, t_stack **st_b, t_stack **lst);
void			ft_instruction(t_stack **lst, int instru);
int				ft_limits(char ***param);
long			ft_atoi_l(const char *str);
void			ft_display_instruction(t_stack **lst);
int				ft_target(t_set *set, t_cdll *stack_a, int a_emptied);
void			ft_put_str_color(char *str, t_cdll *stack, int col, int tar);
#endif

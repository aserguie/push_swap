/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:23:45 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 15:10:27 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_display_stacks(t_set *set, int a_emptied)
{
	t_cdll *st_a;
	t_cdll *st_b;

	st_a = set->stack_a->first;
	st_b = set->stack_b->first;
	if (st_a)
	{
		ft_putstr("ST_A:\t");
		while (st_a)
		{
			ft_put_str_color(ft_itoa(st_a->data), st_a, set->color, ft_target(set, st_a, a_emptied));

			ft_putchar('\t');
			st_a = st_a->next;
		}
		ft_putchar('\n');
	}
	if (st_b)
	{
		ft_putstr("ST_B:\t");
		while (st_b)
		{

			ft_put_str_color(ft_itoa(st_b->data), st_b, set->color, 0);
			ft_putchar('\t');
			st_b = st_b->next;
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	ft_if_display(char **total, int i, int a_emptied, t_set *set)
{
		if (set->frequence != 0 && !(i % set->frequence))
		{
			if (set->aff_instru)
				ft_putendl(*total);
			ft_strclr(*total);
			if (set->aff_stack)
				ft_display_stacks(set, a_emptied);
		}
}

char	*ft_str_space_cat(char *s1, char *s2)
{
	char *res;
	char *res2;

	res = ft_strjoin(s1, s2);
	res2 = ft_strjoin(res, " ");
	free (s1);
	free (s2);
	free (res);
	return (res2);
}

void		ft_free_line(char *s1, char *s2)
{
	if (s1)
		free(s1);
	printf("kjhfkjsdfh\n");
	if (s2)
		free(s2);
	printf("kjhfkjsdfh\n");
}

void		ft_checker(char *line, t_set *set)
{
	int		i;
	int		a_emptied;
	char	*total;

	total = ft_strdup("");
	i = 0;
	a_emptied = 0;
	while (get_next_line(0, &line))
	{
		if (!ft_check_commands(line, &set->stack_a, &set->stack_b))
		{
			write(1, "Error\n", 6);
			ft_free_line(total, line);
//			free(line);
			ft_free_set(set);
			exit (-1);
		}
		else
			i++;
		total = ft_str_space_cat(total, line);
//		free(line);
		if (set->stack_a->len == 0)
			a_emptied = 1;
		ft_if_display(&total, i, a_emptied, set);
	}
	free (total);
//	ft_free_line(total, line);
//	free(line);
}

int		main(int ac, char **av)
{
	t_set	game_set;
	t_set	*set;
	char	*line;

	set = &game_set;
	ft_set(set, &game_set);
	line = NULL;
	if (ac > 1 && !ft_parse(ac, av, &set))
		write(1, "Error\n", 6);
	else if (set->stack_a->first != NULL)
	{
		ft_checker(line, set);
		ft_sorted(&set->stack_a, &set->stack_b) && set->stack_b->len == 0 ?
			write(1, "OK\n", 3) : write(1, "KO\n", 3);
	}
	ft_free_set(set);
	return (0);
}

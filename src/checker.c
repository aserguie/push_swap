/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:23:45 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:31:00 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_if_display(char **total, int i, int a_emptied, t_set *set)
{
	if (set->frequence != 0 && !(i % set->frequence))
	{
		if (set->aff_instru)
			ft_putendl(*total);
		ft_strclr(*total);
		if (set->aff_stack)
		{
			ft_display_stacks(set, a_emptied);
			ft_putchar('\n');
		}
	}
}

char	*ft_str_space_cat(char *s1, char *s2)
{
	char *res;
	char *res2;

	res = ft_strjoin(s1, s2);
	res2 = ft_strjoin(res, " ");
	free(s1);
	free(s2);
	free(res);
	return (res2);
}

void	ft_free_line(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}

void	ft_checker(char *line, t_set *set)
{
	int		i;
	int		a_emptied;
	char	*total;

	total = ft_strdup("");
	i = 0;
	a_emptied = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_check_commands(line, &set->stack_a, &set->stack_b))
		{
			write(1, "Error\n", 6);
			ft_free_line(total, line);
			ft_free_set(set);
			exit(-1);
		}
		i++;
		total = ft_str_space_cat(total, line);
		if (a_emptied == 0 && set->stack_a->len + set->stack_b->len > 5)
			a_emptied = (set->stack_a->len == 0) ? 1 : 0;
		else if (a_emptied == 0)
			a_emptied = (set->stack_a->len == 3) ? 1 : 0;
		ft_if_display(&total, i, a_emptied, set);
	}
	free(total);
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

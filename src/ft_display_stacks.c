/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:20:32 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:29:01 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_put_str_color(char *str, t_cdll *stack, int col, int tar)
{
	char *deb;

	ft_putstr("\t");
	deb = malloc(sizeof(deb) * (1 + 6 * col + 2 * tar));
	if (!col && !tar)
		ft_putstr(str);
	else
	{
		deb = (tar ? "\x1b[4" : "\x1b[");
		if (col == 1)
		{
			deb = (tar ? ft_strjoin(deb, ";38;2;") : ft_strjoin(deb, "38;2;"));
			deb = ft_strjoin(deb, ft_itoa(stack->red));
			deb = ft_strjoin(deb, ";");
			deb = ft_strjoin(deb, ft_itoa(stack->green));
			deb = ft_strjoin(deb, ";0");
		}
		deb = ft_strjoin(deb, "m");
		deb = ft_strjoin(deb, str);
		deb = ft_strjoin(deb, "\x1b[0m");
		ft_putstr(deb);
	}
	free(deb);
}

void	ft_display_stacks(t_set *set, int a_emptied)
{
	t_cdll *st;

	st = set->stack_a->first;
	if (st)
	{
		ft_putstr("ST_A:");
		while (st)
		{
			ft_put_str_color(ft_itoa(st->data), st, set->color,
					ft_target(set, st, a_emptied));
			st = st->next;
		}
		ft_putchar('\n');
	}
	st = set->stack_b->first;
	if (st)
	{
		ft_putstr("ST_B:");
		while (st)
		{
			ft_put_str_color(ft_itoa(st->data), st, set->color, 0);
			st = st->next;
		}
		ft_putchar('\n');
	}
}

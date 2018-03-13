/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:14:07 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:06:41 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			ft_sort_help_bis(t_stack **st_b, t_stack **lst, int min, int max)
{
	if ((*st_b)->first->next)
	{
		if (((*st_b)->first)->index <= (min + max) / 2)
		{
			if ((*st_b)->len > 2)
			{
				ft_rotate(st_b);
				ft_instruction(lst, 3);
			}
			else
			{
				ft_swap(st_b);
				ft_instruction(lst, 10);
			}
		}
		if ((*st_b)->first->index < (*st_b)->first->next->index)
		{
			ft_swap(st_b);
			ft_instruction(lst, 10);
		}
	}
	return (0);
}

void		ft_apply(t_stack **stack, t_stack **lst, int n, int way)
{
	while (n > 0)
	{
		if (way == 1)
		{
			ft_rotate(stack);
			ft_instruction(lst, 2);
		}
		else
		{
			ft_rev_rotate(stack);
			ft_instruction(lst, -2);
		}
		n--;
	}
}

void		ft_shortest_way(t_stack **stack, int min, int max, t_stack **lst)
{
	t_cdll	*ptr;
	int		first;
	int		last;
	int		i;

	ptr = (*stack)->first;
	first = -1;
	last = 0;
	i = 0;
	while (ptr)
	{
		if (ptr->index <= max && ptr->index >= min && first == -1)
			first = i;
		if (ptr->index <= max && ptr->index >= min)
			last = i;
		ptr = ptr->next;
		i++;
	}
	if (first < 0)
		first = 1;
	first <= (i - last) ? ft_apply(stack, lst, first, 1) :
		ft_apply(stack, lst, i - last, -1);
}

int			ft_long(t_stack **st_a, t_stack **st_b, t_stack **lst)
{
	int	min;
	int	max;

	if (!(*st_a)->first)
		return (1);
	min = ft_min_max(st_a, st_b, -1);
	max = ft_min_max(st_a, st_b, 1);
	if (((*st_a)->first)->index <= max && (*st_a)->first->index >= min)
	{
		ft_pop_node_cdll(st_a, st_b);
		ft_instruction(lst, -1);
		ft_sort_help_bis(st_b, lst, min, max);
	}
	else
		ft_shortest_way(st_a, min, max, lst);
	ft_long(st_a, st_b, lst);
	return (0);
}

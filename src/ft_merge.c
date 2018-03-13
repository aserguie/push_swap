/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:00:54 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:02:41 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_st_b(t_stack **st_b, t_stack **lst)
{
	if ((*st_b)->first->next)
	{
		if ((*st_b)->last->data > (*st_b)->first->data)
		{
			ft_rev_rotate(st_b);
			ft_instruction(lst, -3);
		}
		else if ((*st_b)->first->next->data > (*st_b)->first->data
				&& (*st_b)->first->next->data < (*st_b)->last->data)
		{
			ft_swap(st_b);
			ft_instruction(lst, 10);
		}
		else if ((*st_b)->first->next->data > (*st_b)->first->data
				&& (*st_b)->first->next->data >= (*st_b)->last->data)
		{
			ft_rotate(st_b);
			ft_instruction(lst, 3);
		}
	}
}

void	ft_sort_short_st_b(t_stack **st_b, t_stack **lst)
{
	if ((*st_b)->first->next)
	{
		if ((*st_b)->first->next->data > (*st_b)->first->data
				&& (*st_b)->first->next->data >= (*st_b)->last->data)
		{
			ft_rotate(st_b);
			ft_instruction(lst, 3);
		}
		else if ((*st_b)->last->data > (*st_b)->first->data
				&& (*st_b)->last->data >= (*st_b)->first->next->data)
		{
			ft_rev_rotate(st_b);
			ft_instruction(lst, -3);
		}
	}
}

void	ft_insert_short(t_stack **st_a, t_stack **st_b, t_stack **lst)
{
	int		i;

	i = 0;
	while ((*st_b)->first->data > (*st_a)->first->data)
	{
		ft_rotate(st_a);
		ft_instruction(lst, 2);
		i++;
	}
	ft_pop_node_cdll(st_b, st_a);
	ft_instruction(lst, 1);
	while (i > 0)
	{
		ft_rev_rotate(st_a);
		ft_instruction(lst, -2);
		i--;
	}
}

void	ft_insert(t_stack **st_a, t_stack **st_b, t_stack **lst)
{
	while ((*st_b)->first->data > (*st_a)->first->data)
	{
		ft_rotate(st_a);
		ft_instruction(lst, 2);
	}
	while (((*st_a)->last->data < (*st_a)->first->data)
			&& (*st_b)->first->data < (*st_a)->last->data)
	{
		ft_rev_rotate(st_a);
		ft_instruction(lst, -2);
	}
	ft_pop_node_cdll(st_b, st_a);
	ft_instruction(lst, 1);
	if ((*st_a)->last->prev && (*st_a)->last->data < (*st_a)->last->prev->data)
	{
		while (((*st_b) && (*st_b)->first->data < (*st_a)->first->data)
				&& ((*st_b)->first->data > (*st_a)->first->data))
		{
			ft_pop_node_cdll(st_b, st_a);
			ft_instruction(lst, 1);
		}
	}
}

int		ft_merge(t_stack **st_a, t_stack **st_b, t_stack **lst)
{
	if ((*st_b)->first)
	{
		ft_pop_node_cdll(st_b, st_a);
		ft_instruction(lst, 1);
	}
	while ((*st_b)->first)
	{
		if ((*st_a)->len + (*st_b)->len > 5)
		{
			ft_sort_st_b(st_b, lst);
			ft_insert(st_a, st_b, lst);
		}
		else
		{
			ft_sort_short_st_b(st_b, lst);
			ft_insert_short(st_a, st_b, lst);
		}
	}
	return (0);
}

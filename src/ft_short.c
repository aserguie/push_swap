/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:06:09 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/12 16:46:58 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_three(t_stack **curr, t_stack **lst)
{
	if ((*curr)->first->data > (*curr)->first->next->data
			&& (*curr)->first->data > (*curr)->last->data)
	{
		ft_rotate(curr);
		ft_instruction(lst, 2);
	}
	if ((*curr)->first->data > (*curr)->first->next->data
			&& (*curr)->first->data < (*curr)->last->data)
	{
		ft_swap(curr);
		ft_instruction(lst, 9);
	}
	if ((*curr)->first->data < (*curr)->first->next->data
			&& (*curr)->first->next->data > (*curr)->last->data)
	{
		ft_rev_rotate(curr);
		ft_instruction(lst, -2);
	}
	if ((*curr)->first->data > (*curr)->first->next->data)
	{
		ft_swap(curr);
		ft_instruction(lst, 9);
	}
	return (0);
}

int	ft_five(t_stack **curr, t_stack **help, t_stack **lst)
{
	if ((*help)->len == 3)
		return (0);
	if ((*curr)->first->data < (*curr)->first->next->data
			&& (*curr)->first->data < (*curr)->last->data)
	{
		ft_pop_node_cdll(curr, help);
		ft_instruction(lst, -1);
	}
	else if ((*curr)->last->data < (*curr)->first->data
			&& (*curr)->last->data < (*curr)->first->next->data)
	{
		ft_rev_rotate(curr);
		ft_instruction(lst, -2);
	}
	else
	{
		ft_rotate(curr);
		ft_instruction(lst, 2);
	}
	ft_five(curr, help, lst);
	return (0);
}

int	ft_short(t_stack **curr, t_stack **help, t_stack **lst)
{
	if ((*curr)->len <= 3)
	{
		ft_three(curr, lst);
		return (0);
	}
	if ((*curr)->len <= 5)
	{
		ft_five(curr, help, lst);
		ft_three(curr, lst);
		ft_merge(curr, help, lst);
		return (0);
	}
	return (0);
}

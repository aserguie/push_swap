/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:14:22 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:41:39 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_display_instruction_2(t_cdll **lst)
{
	if ((*lst)->data == 9)
		ft_putstr("sa\n");
	else if ((*lst)->data == 10)
		ft_putstr("sb\n");
	else if ((*lst)->data == 19)
		ft_putstr("ss\n");
	return (1);
}

void	ft_display_instruction(t_stack **lst)
{
	while ((*lst)->last)
	{
		if ((*lst)->last->data == 1)
			ft_putstr("pa\n");
		else if ((*lst)->last->data == -1)
			ft_putstr("pb\n");
		else if ((*lst)->last->data == 2)
			ft_putstr("ra\n");
		else if ((*lst)->last->data == -2)
			ft_putstr("rra\n");
		else if ((*lst)->last->data == 3)
			ft_putstr("rb\n");
		else if ((*lst)->last->data == -3)
			ft_putstr("rrb\n");
		else if ((*lst)->last->data == 5)
			ft_putstr("rr\n");
		else if ((*lst)->last->data == -5)
			ft_putstr("rrr\n");
		else if (ft_display_instruction_2(&(*lst)->last))
			;
		(*lst)->last = (*lst)->last->prev;
	}
}

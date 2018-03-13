/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:00:18 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 16:59:52 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rev_rotate(t_stack **stack)
{
	t_cdll *ptr;

	if ((*stack)->len >= 2)
	{
		ptr = (*stack)->last;
		(*stack)->first->prev = (*stack)->last;
		(*stack)->last->next = (*stack)->first;
		(*stack)->first = (*stack)->last;
		(*stack)->last = ptr->prev;
		(*stack)->last->next = NULL;
		(*stack)->first->prev = NULL;
	}
}

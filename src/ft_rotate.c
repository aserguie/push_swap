/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:58:31 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 16:59:28 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_cdll *ptr;

	if ((*stack)->len >= 2)
	{
		ptr = (*stack)->first;
		ptr = ptr->next;
		(*stack)->first->prev = (*stack)->last;
		(*stack)->last->next = (*stack)->first;
		(*stack)->last = (*stack)->first;
		(*stack)->last->next = NULL;
		(*stack)->first = ptr;
		(*stack)->first->prev = NULL;
	}
}

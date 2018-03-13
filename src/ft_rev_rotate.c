/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:00:18 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/08 16:16:57 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rev_rotate(t_stack **stack)
{
	t_cdll *ptr;

	//printf("rev_0\n");
	if ((*stack)->len >= 2)
	{
	//printf("rev_1\n");
		ptr = (*stack)->last;
	//printf("rev_2\n");
		(*stack)->first->prev = (*stack)->last;
	//printf("rev_3\n");
		(*stack)->last->next = (*stack)->first;
	//printf("rev_4\n");
		(*stack)->first = (*stack)->last;
	//printf("rev_5\n");
	//printf("first = %d\n", (*stack)->first->data);
	//printf("last = %d\n", (*stack)->last->data);
	//printf("pre_last = %d\n", (*stack)->last->prev->data);
		(*stack)->last = ptr->prev;
	//printf("rev_6\n");
		(*stack)->last->next = NULL;
	//printf("rev_7\n");
		(*stack)->first->prev = NULL;
	//printf("rev_8\n");
	}
}

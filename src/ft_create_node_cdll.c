/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node_cdll.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 21:00:42 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:09:16 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_create_node_cdll(t_stack **stack_1, t_stack **stack_2)
{
	if ((*stack_2)->first != NULL)
	{
		(*stack_1)->first = (*stack_2)->first;
		(*stack_2)->first = (*stack_2)->first->next;
		if ((*stack_2)->first != NULL)
			(*stack_2)->first->prev = NULL;
		(*stack_1)->first->next = NULL;
		(*stack_1)->first->prev = NULL;
		(*stack_1)->last = (*stack_1)->first;
		(*stack_1)->len = 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:52:05 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 16:58:37 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_cdll *ptr;
	t_cdll *ptr_2;
	t_cdll *ptr_3;

	if ((*stack)->len >= 2)
	{
		ptr = (*stack)->first;
		ptr_2 = (*stack)->first->next;
		(*stack)->first = ptr_2;
		ptr->next = ptr_2->next;
		if (ptr->next != NULL)
		{
			ptr_3 = ptr->next;
			ptr_3->prev = ptr;
		}
		ptr_2->next = ptr;
		ptr_2->prev = NULL;
		if (ptr->next == NULL)
			(*stack)->last = ptr;
	}
}

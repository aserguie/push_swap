/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:52:05 by aserguie          #+#    #+#             */
/*   Updated: 2018/02/22 18:17:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//void	ft_swap(t_stack **stack)
//{
//	int		data;
//	int		index;
//
//	if ((*stack)->len >= 2)
//	{
//		data = (*stack)->first->data;
//		index = (*stack)->first->index;
//		(*stack)->first->data = (*stack)->first->next->data;
//		(*stack)->first->index = (*stack)->first->next->index;
//		(*stack)->first->next->data = data;
//		(*stack)->first->next->index = index;
//	}
//}

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

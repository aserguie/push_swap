/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:58:31 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/08 12:06:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_cdll *ptr;

	//printf("bla0\n");
	//printf("%d ", (*stack)->first->data);
//	//printf("bla0\n");
	//printf("%d ", (*stack)->first->next->data);
//	//printf("bla0\n");
	//printf("%d ", (*stack)->last->prev->data);
//	//printf("bla0\n");
	//printf("%d \n", (*stack)->last->data);

	if ((*stack)->len >= 2)
	{
	//printf("bla\n");
		ptr = (*stack)->first;
	//printf("bla\n");
		ptr = ptr->next;
	//printf("bla\n");
		(*stack)->first->prev = (*stack)->last;
	//printf("bla\n");
		(*stack)->last->next = (*stack)->first;
	//printf("bla\n");
		(*stack)->last = (*stack)->first;
	//printf("bla\n");
		(*stack)->last->next = NULL;
	//printf("bla\n");
		(*stack)->first = ptr;
	//printf("bla\n");
		(*stack)->first->prev = NULL;
	//printf("bla100\n");
	}
	//printf("%d ", (*stack)->first->data);
	//printf("%d ", (*stack)->first->next->data);
	//printf("%d ", (*stack)->last->prev->data);
	//printf("%d \n", (*stack)->last->data);
}

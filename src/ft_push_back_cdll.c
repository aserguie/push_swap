/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_cdll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:59:12 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/08 12:07:00 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push_cdll(t_stack **stack_1, t_stack **stack_2)
{
	t_cdll	*new;

	new = malloc(sizeof(t_cdll));
	if (new == NULL)
		exit(-1);
	new->prev = NULL;
	new->next = (*stack_1)->first;
	(*stack_1)->first->prev = new;
	(*stack_1)->first = new;
	new->data = (*stack_2)->first->data;
	new->index = (*stack_2)->first->index;
	new->red = (*stack_2)->first->red;
	new->green = (*stack_2)->first->green;
	new->target = (*stack_2)->first->target;
	(*stack_1)->len++;
}

void	ft_push_back_cdll(t_stack **stack_1, t_stack **stack_2)
{
	if ((*stack_1)->first == NULL)
		ft_create_node_cdll(stack_1, stack_2);
	else
		ft_push_cdll(stack_1, stack_2);
}

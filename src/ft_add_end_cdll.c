/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_end_cdll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:59:22 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 13:32:32 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_append_cdll(t_stack **stack, int value, int index)
{
	t_cdll *new;

	new = malloc(sizeof(t_cdll));
	if (new == NULL)
		exit(-1);
	new->prev = (*stack)->last;
	(*stack)->last->next = new;
	new->next = NULL;
	new->data = value;
	new->index = index;
	(*stack)->last = new;
	(*stack)->len++;
}

void	ft_add_end_cdll(t_stack **stack, int value, int index)
{
	if ((*stack)->first == NULL)
		ft_create_node_list(stack, value, index);
	else
		ft_append_cdll(stack, value, index);
}

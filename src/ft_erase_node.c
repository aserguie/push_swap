/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:51:31 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/08 17:50:00 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_erase_node_cdll(t_stack **stack)
{
	if ((*stack)->len >= 2)
	{
		(*stack)->first = (*stack)->first->next;
		free((*stack)->first->prev);
		(*stack)->first->prev = NULL;
		(*stack)->len = (*stack)->len - 1;
	}
	else
	{
		free((*stack)->first);
		(*stack)->first = NULL;
		(*stack)->last = NULL;
		(*stack)->len = 0;
	}
}

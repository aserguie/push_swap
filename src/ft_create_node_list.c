/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node_cdll.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 21:00:42 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/08 11:15:29 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_create_node_list(t_stack **stack, int value, int index)
{
	t_cdll	*new;

	new = malloc(sizeof(t_cdll));
	if (new == NULL)
		exit(-1);
	new->data = value;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	(*stack)->first = new;
	(*stack)->last = new;
	(*stack)->len = 1;
}

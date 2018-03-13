/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:11:40 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/12 15:59:31 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *st_a;

	st_a = *stack_a;
	if (st_a->last && (st_a->last->index != st_a->len + (*stack_b)->len))
		return (0);
	while (st_a->first->next)
	{
		if (st_a->first->index != st_a->first->next->index - 1)
			return (0);
		st_a->first = st_a->first->next;
	}
	return (1);
}

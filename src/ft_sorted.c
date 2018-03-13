/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:11:40 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 16:58:54 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_cdll	*ptr;
	int		i;

	i = 1;
	ptr = NULL;
	if ((*stack_a)->first)
		ptr = (*stack_a)->first;
	while (ptr)
	{
		if (ptr->index != i)
			return (0);
		i++;
		ptr = ptr->next;
	}
	if ((*stack_b)->first && i != (*stack_a)->len + (*stack_b)->len)
		return (0);
	return (1);
}

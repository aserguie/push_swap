/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:52:05 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/12 19:21:19 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_target(t_set *set, t_cdll *stack_a, int a_emptied)
{
	int	min;
	int max;

	if (a_emptied == 1 || set->target == 0)
		return (0);
	min = ft_min_max(&set->stack_a, &set->stack_b, -1);
	max = ft_min_max(&set->stack_a, &set->stack_b, 1);
	if (stack_a->index <= max && stack_a->index >= min)
		return (1);
	else
		return (0);
}

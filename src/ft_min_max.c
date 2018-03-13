/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:05:48 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:05:51 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			ft_min_max(t_stack **st_a, t_stack **st_b, int i)
{
	int min;
	int max;

	if ((*st_a)->len > 1000)
		return (((*st_a)->len + (*st_b)->len) / 2
				+ i * ((*st_a)->len / 2 * ((*st_b)->len / (*st_a)->len + 1)));
	else if ((*st_a)->len > 250)
		return (((*st_a)->len + (*st_b)->len) / 2
				+ i * (40 * ((*st_b)->len / 80 + 1)));
	else if ((*st_a)->len > 100)
		return (((*st_a)->len + (*st_b)->len) / 2
				+ i * (25 * ((*st_b)->len / 50 + 1)));
	else
	{
		min = ((*st_a)->len + (*st_b)->len) / 4 + 1;
		max = (3 * ((*st_a)->len + (*st_b)->len)) / 4 + 1;
		if ((max - min) <= (*st_b)->len)
		{
			min = (*st_a)->len / 4;
			max = (*st_a)->len + (*st_b)->len - min;
		}
		return (i == 1 ? max : min);
	}
}

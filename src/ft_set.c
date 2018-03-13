/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:37:55 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/12 18:31:59 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_set(t_set *set, t_set *game_set)
{
	set = game_set;
	(set)->stack_a = &(set->sta_a);
	set->stack_b = &(set->sta_b);
	set->instru = &(set->inst);
	set->instru->first = NULL;
	set->stack_a->first = NULL;
	set->stack_b->first = NULL;
	set->instru->last = NULL;
	set->stack_a->last = NULL;
	set->stack_b->last = NULL;
	set->instru->len = 0;
	set->stack_a->len = 0;
	set->stack_b->len = 0;
	set->color = 0;
	set->target = 0;
	set->aff_instru = 0;
	set->aff_stack = 0;
	set->frequence = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_node_cdll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:06:03 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:00:48 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_pop_node_cdll(t_stack **st_1, t_stack **st_2)
{
	t_cdll *ptr_1;
	t_cdll *ptr_2;

	if ((*st_1)->first != NULL)
	{
		ptr_1 = (*st_1)->first;
		ptr_2 = NULL;
		(*st_1)->first = (*st_1)->first->next;
		if ((*st_1)->first != NULL)
			(*st_1)->first->prev = NULL;
		(*st_1)->len = ((*st_1)->len > 0 ? (*st_1)->len - 1 : 0);
		if ((*st_2)->first != NULL)
			ptr_2 = (*st_2)->first;
		(*st_2)->first = ptr_1;
		if (ptr_2 != NULL)
			ptr_2->prev = (*st_2)->first;
		(*st_2)->first->next = ptr_2;
		(*st_2)->first->prev = NULL;
		((*st_2)->len)++;
		if ((*st_2)->len == 1)
			(*st_2)->last = (*st_2)->first;
	}
}

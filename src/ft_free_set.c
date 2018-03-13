/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:29:38 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/09 18:29:40 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_free_dllist(t_cdll *dllist)
{
	t_cdll *ptr;

	ptr = NULL;
	while (dllist != NULL)
	{
		ptr = dllist;
		dllist = dllist->next;
		free(ptr);
	}
}

void	ft_free_set(t_set *set)
{
	ft_free_dllist((&set->sta_a)->first);
	ft_free_dllist((&set->sta_b)->first);
	ft_free_dllist((&set->inst)->first);
}

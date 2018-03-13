/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:14:22 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/12 16:47:19 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_add_if(t_stack **lst, int instru)
{
	if ((((*lst)->first->data + instru == 0) && ((*lst)->first->next && (*lst)->first->next->data != -1) && ((*lst)->first->data != -1))
			|| (*lst)->first->data + instru == 18
			|| (*lst)->first->data + instru == 20
			|| (*lst)->first->data + instru == 38)
		return (0);
	else if ((*lst)->first->data + instru == 5
			|| (*lst)->first->data + instru == -5)
		return ((*lst)->first->data + instru);
	else if ((*lst)->first->data + instru == 19)
		return (19);
	else if ((*lst)->first->data + instru == 28)
		return (10);
	else if ((*lst)->first->data + instru == 29)
		return (9);
	else
		return (instru);
}

void	ft_push_instru(t_stack **lst, int instru)
{
	t_cdll *new;

	if ((*lst)->first->data == 0)
		(*lst)->first->data = instru;
	else if (ft_add_if(lst, instru) == 0)
		ft_erase_node_cdll(lst);
	else if ((*lst)->first->data + instru == 5
			|| (*lst)->first->data + instru == -5
			|| (*lst)->first->data + instru == 19
			|| (*lst)->first->data + instru == 28
			|| (*lst)->first->data + instru == 29)
		(*lst)->first->data = ft_add_if(lst, instru);
	else
	{
		new = malloc(sizeof(t_cdll));
		if (new == NULL)
			exit(-1);
		new->prev = NULL;
		new->next = (*lst)->first;
		(*lst)->first->prev = new;
		(*lst)->first = new;
		(*lst)->len++;
		new->data = instru;
	}
}

void	ft_instruction(t_stack **lst, int instru)
{
	if ((*lst)->first == NULL)
		ft_create_node_list(lst, instru, 0);
	else
		ft_push_instru(lst, instru);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:14:22 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/12 16:47:07 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_display_instruction(t_stack **lst)
{
	while ((*lst)->last)
			{
				if ((*lst)->last->data == 1)
					printf("pa\n");
				else if ((*lst)->last->data == -1)
					printf("pb\n");
				else if ((*lst)->last->data == 2)
					printf("ra\n");
				else if ((*lst)->last->data == -2)
					printf("rra\n");
				else if ((*lst)->last->data == 3)
					printf("rb\n");
				else if ((*lst)->last->data == -3)
					printf("rrb\n");
				else if ((*lst)->last->data == 5)
					printf("rr\n");
				else if ((*lst)->last->data == -5)
					printf("rrr\n");
				else if ((*lst)->last->data == 9)
					printf("sa\n");
				else if ((*lst)->last->data == 10)
					printf("sb\n");
				else if ((*lst)->last->data == 19)
					printf("ss\n");
				(*lst)->last = (*lst)->last->prev;
			}
}

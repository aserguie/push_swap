/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:17:09 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:07:04 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_color(t_stack **stack)
{
	t_cdll	*ptr1;

	ptr1 = (*stack)->first;
	while (ptr1)
	{
		if (ptr1->index < (*stack)->len / 2)
		{
			ptr1->red = (255 * 2 * ptr1->index) / (*stack)->len;
			if (ptr1->red > 255)
				ptr1->red = 255;
			ptr1->green = 255;
		}
		else
		{
			ptr1->red = 255;
			ptr1->green = 510 - (255 * 2 * ptr1->index) / (*stack)->len;
			if (ptr1->green > 255)
				ptr1->green = 255;
		}
		ptr1 = ptr1->next;
	}
}

int		ft_index(t_stack **stack)
{
	t_cdll	*ptr1;
	t_cdll	*ptr2;
	int		i;
	int		no_doublon;

	no_doublon = 1;
	ptr1 = (*stack)->first;
	while (ptr1)
	{
		i = 1;
		ptr2 = (*stack)->first;
		while (ptr2)
		{
			no_doublon = ((ptr1->data == ptr2->data
						&& (ptr1 != ptr2)) ? 0 : no_doublon);
			if (ptr1->data > ptr2->data)
				i++;
			ptr2 = ptr2->next;
		}
		ptr1->index = i;
		ptr1->target = 0;
		ptr1 = ptr1->next;
	}
	ft_color(stack);
	return (no_doublon);
}

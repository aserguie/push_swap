/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:18:02 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/12 20:16:34 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_put_str_color(char *str, t_cdll *stack, int col, int tar)
{
	char *deb;

	deb = malloc(sizeof(deb) * (1 + 6 * col + 2 * tar));
	if (!col && !tar)
		ft_putstr(str);
	else
	{
		deb = (tar ? "\x1b[4" : "\x1b[");
		if (col == 1)
		{
			deb = (tar ? ft_strjoin(deb, ";38;2;") : ft_strjoin(deb, "38;2;"));
			deb = ft_strjoin(deb ,ft_itoa(stack->red));
			deb = ft_strjoin(deb, ";");
			deb = ft_strjoin(deb, ft_itoa(stack->green));
			deb = ft_strjoin(deb, ";0");
		}
		deb = ft_strjoin(deb, "m");
		deb = ft_strjoin(deb, str);
		deb = ft_strjoin(deb, "\x1b[0m");
		ft_putstr(deb);
	}
	free(deb);
}

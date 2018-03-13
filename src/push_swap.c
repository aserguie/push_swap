/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:13:02 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 16:57:29 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		main(int ac, char **av)
{
	t_set	game_set;
	t_set	*set;

	set = &game_set;
	ft_set(set, &game_set);
	if (!ft_parse(ac, av, &set))
		write(1, "Error\n", 6);
	else
	{
		if (set->stack_a->first != NULL && !ft_sorted(&set->stack_a,
					&set->stack_b))
		{
			ft_instruction(&(set->instru), 0);
			set->stack_a->len <= 5 ? ft_short(&set->stack_a, &set->stack_b,
					&set->instru) : ft_long(&(set->stack_a), &(set->stack_b),
						&(set->instru));
			ft_merge(&(set->stack_a), &(set->stack_b), &(set->instru));
			ft_display_instruction(&(set->instru));
		}
	}
	ft_free_set(set);
	return (0);
}

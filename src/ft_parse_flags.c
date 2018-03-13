/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:19:54 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 17:04:49 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_parse_flags_1(int i, char **av, t_set **set)
{
	if (!ft_strcmp(av[i], "-color") && (*set)->color == 0)
		(*set)->color = 1;
	else if (!ft_strcmp(av[i], "-stack") && (*set)->aff_stack == 0)
	{
		(*set)->aff_stack = 1;
		if ((*set)->frequence == 0)
			(*set)->frequence = 1;
	}
	else if (!ft_strcmp(av[i], "-target") && (*set)->target == 0)
		(*set)->target = 1;
	else if (!ft_strcmp(av[i], "-instru") && (*set)->aff_instru == 0)
	{
		(*set)->aff_instru = 1;
		if ((*set)->frequence == 0)
			(*set)->frequence = 1;
	}
	else
		return (0);
	return (1);
}

int		ft_parse_flags(int ac, char **av, t_set **set)
{
	int i;

	i = 1;
	while (i < ac && i <= 7)
	{
		if (ft_parse_flags_1(i, av, set))
			;
		else if (!ft_strcmp(av[i], "-freq"))
		{
			if (i < 7 && (i + 2) < ac && ft_is_numbers(av[i + 1], 0)
					&& ft_atoi_l(av[i + 1]) > 0
					&& ft_atoi_l(av[i + 1]) < INT_MAX)
			{
				(*set)->frequence = ft_atoi(av[i + 1]);
				i++;
			}
			else
				return (-1);
		}
		else
			return (i);
		i++;
	}
	return (i - 1);
}

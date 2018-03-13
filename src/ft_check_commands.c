/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:31:36 by aserguie          #+#    #+#             */
/*   Updated: 2018/02/08 18:22:53 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_check_commands_2(char *line, t_stack **st_a, t_stack **st_b)
{
	if (!ft_strcmp(line, "rr"))
	{
		ft_rotate(st_a);
		ft_rotate(st_b);
	}
	else if (!ft_strcmp(line, "rra"))
		ft_rev_rotate(st_a);
	else if (!ft_strcmp(line, "rrb"))
		ft_rev_rotate(st_b);
	else if (!ft_strcmp(line, "rrr"))
	{
		ft_rev_rotate(st_a);
		ft_rev_rotate(st_b);
	}
	else
		return (0);
	return (1);
}

int		ft_check_commands(char *line, t_stack **st_a, t_stack **st_b)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap(st_a);
	else if (!ft_strcmp(line, "sb"))
		ft_swap(st_b);
	else if (!ft_strcmp(line, "ss"))
	{
		ft_swap(st_a);
		ft_swap(st_b);
	}
	else if (!ft_strcmp(line, "pa"))
		ft_pop_node_cdll(st_b, st_a);
	else if (!ft_strcmp(line, "pb"))
		ft_pop_node_cdll(st_a, st_b);
	else if (!ft_strcmp(line, "ra"))
		ft_rotate(st_a);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate(st_b);
	else if (ft_check_commands_2(line, st_a, st_b))
		return (1);
	else
		return (0);
	return (1);
}

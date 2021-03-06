/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:41:56 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 18:03:55 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_limits(char ***param)
{
	int i;
	int j;

	i = 0;
	while (param[i])
	{
		j = 0;
		while (param[i][j])
		{
			if ((ft_isdigit(param[i][j][0]) && ft_strlen(param[i][j]) > 10)
					|| ft_atoi_l(param[i][j]) > INT_MAX
					|| ft_strlen(param[i][j]) > 11
					|| ft_atoi_l(param[i][j]) < INT_MIN)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:24:42 by aserguie          #+#    #+#             */
/*   Updated: 2018/02/08 18:22:45 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atoi_l(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (((9 <= str[i]) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while ((str[i] != '\0') && ('0' <= str[i]) && (str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

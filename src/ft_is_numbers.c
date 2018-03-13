/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:02:25 by aserguie          #+#    #+#             */
/*   Updated: 2018/02/08 18:23:25 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_numbers(char *str, int ctr)
{
	if (*str == '\0')
		return (ctr);
	else if (*str == '+' || *str == '-')
	{
		if (ft_isdigit((int)(*(str + 1))))
			ft_is_numbers(str + 1, 1);
		else
			return (0);
	}
	else if (!ft_isdigit((int)(*str)) && !(*str == ' '))
		return (0);
	else if (ft_isdigit((int)(*str))
			&& (*(str + 1) == '+' || *(str + 1) == '-'))
		return (0);
	else if (ft_isdigit((int)(*str)))
		ctr = 1;
	return (ft_is_numbers(str + 1, ctr));
}

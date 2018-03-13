/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:39:39 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/13 18:03:53 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_clear_param(char ***param)
{
	int	i;
	int j;
	int	ret;

	i = 0;
	ret = 1;
	while (param[i])
	{
		j = 0;
		while (param[i][j])
		{
			ft_memdel((void **)(&param[i][j]));
			ret = ((param[i][j] == NULL) ? ret : 0);
			j++;
		}
		ft_memdel((void **)(&param[i]));
		ret = ((param[i] == NULL) ? ret : 0);
		i++;
	}
	ft_memdel((void **)(&param));
	ret = ((param == NULL) ? ret : 0);
	return (ret);
}

int		ft_error(char ***param)
{
	int i;
	int j;

	i = 0;
	if (!ft_limits(param))
		return (ft_clear_param(param));
	while (param[i])
	{
		j = 0;
		while (param[i][j])
		{
			if (!ft_is_numbers(param[i][j], 0))
			{
				return (ft_clear_param(param));
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	***ft_parse_param(char ***param, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!(param = (char***)malloc(sizeof(char**) * ac)))
		return (NULL);
	while (j < ac - 1)
	{
		param[j] = ft_strsplit(av[j + 1], ' ');
		j++;
	}
	param[j] = NULL;
	return (param);
}

int		ft_parse_links(char ***param, t_stack **st_a)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	while (param[i])
	{
		j = 0;
		while (param[i][j])
		{
			ft_add_end_cdll(st_a, ft_atoi(param[i][j]), k);
			j++;
			k++;
		}
		i++;
	}
	ft_clear_param(param);
	return (ft_index(st_a));
}

int		ft_parse(int ac, char **av, t_set **set)
{
	char	***param;
	int		flags;

	flags = 1;
	param = NULL;
	flags = (ft_strcmp(av[0], "./push_swap") ?
			ft_parse_flags(ac, av, set) : 1);
	if (flags == -1)
		return (0);
	param = ft_parse_param(param, ac - flags + 1, &av[flags - 1]);
	if (!param || ft_error(param))
		return (0);
	if (!ft_parse_links(param, &(*set)->stack_a))
		return (0);
	return (1);
}

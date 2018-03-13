/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:14:07 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/12 16:44:11 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			ft_sort_help_bis(t_stack **st_b, t_stack **lst, int min, int max)
{
	if ((*st_b)->first->next)
	{
		if (((*st_b)->first)->index <= (min + max) / 2)
		{
			if ((*st_b)->len > 2)
			{
				ft_rotate(st_b);
				ft_instruction(lst, 3);
			}
			else
			{
				ft_swap(st_b);
				ft_instruction(lst, 10);
			}
		}
		if ((*st_b)->first->index < (*st_b)->first->next->index)
		{
			ft_swap(st_b);
			ft_instruction(lst, 10);
		}
	}
	return (0);
}

void		ft_apply(t_stack **stack, t_stack **lst, int n, int way)
{
	while (n > 0)
	{
		if (way == 1)
		{
			ft_rotate(stack);
			ft_instruction(lst, 2);
		}
		else
		{
			ft_rev_rotate(stack);
			ft_instruction(lst, -2);
		}
		n--;
	}
}

void		ft_shortest_way(t_stack **stack, int min, int max, t_stack **lst)
{
	t_cdll	*ptr;
	int		first;
	int		last;
	int		i;

	ptr = (*stack)->first;
	first = -1;
	last = 0;
	i = 0;
	while (ptr)
	{
		if (ptr->index <= max && ptr->index >= min && first == -1)
			first = i;
		if (ptr->index <= max && ptr->index >= min)
			last = i;
		ptr = ptr->next;
		i++;
	}
	if (first < 0)
		first = 1;
//	//printf("%d %d %d\n", first, i, last);
//	exit(0);
	first <= (i - last) ? ft_apply(stack, lst, first, 1) :
		ft_apply(stack, lst, i - last, -1);
	//printf("break\n");
}

int			ft_long(t_stack **st_a, t_stack **st_b, t_stack **lst)
{
	int	min;
	int	max;
//	static int ctr = 0;

/*	
	printf("%d ", (*st_a)->first->data);
	ft_pop_node_cdll(st_a, st_b);
	printf("%d ", (*st_a)->first->data);

	ft_pop_node_cdll(st_a, st_b);
	printf("%d ", (*st_b)->first->data);

	printf("%d ", (*st_b)->last->data);
	exit (0);
	ctr++;
	//printf("ctr = %d", ctr);
//	//printf("%d\n", (*st_a)->len);
//	//printf("%d\n", (*st_b)->len);
//	if (ctr == 11)
//		exit (0);*/
	if (!(*st_a)->first)
		return (1);
	min = ft_min_max(st_a, st_b, -1);
	max = ft_min_max(st_a, st_b, 1);
//	ft_target(st_a, min, max);
	//printf("\t--\t %d\n", min);
	//printf("\t--\t %d\n", max);

	if (((*st_a)->first)->index <= max && (*st_a)->first->index >= min)
	{
		//printf("in dans out");
		//printf("\nlen_a = %d ---\n", (*st_a)->len);
		ft_pop_node_cdll(st_a, st_b);
		//printf("len_a = %d ---\n\n\n", (*st_a)->len);
		ft_instruction(lst, -1);
//		exit (0);
		ft_sort_help_bis(st_b, lst, min, max);
	//printf("end_sort\n");
	}
	else
		ft_shortest_way(st_a, min, max, lst);
	//printf("\t\t %d dans len_a = %d et len_b = %d\n", (*st_a)->first->data, (*st_a)->len, (*st_b)->len);
	//printf("\t\t %d\n", min);
	//printf("\t\t %d\n", max);
/*
	t_cdll *ptr0 = (*st_a)->first;
	int j = 0;
	while ((*st_a)->first)
	{
		j++;
		printf("%d ", (*st_a)->first->data);
		(*st_a)->first = (*st_a)->first->next;
	}

		t_cdll *ptr = (*st_b)->first;
	int i = 0;
	while ((*st_b)->first)
	{
		i++;
		printf("%d ", (*st_b)->first->data);
		(*st_b)->first = (*st_b)->first->next;
	}
	printf("\n i = %d\n", i);
//printf("\nlen_a = %d\n", (*st_a)->len);
(*st_b)->first = ptr;
(*st_a)->first = ptr0;*/
	ft_long(st_a, st_b, lst);
	//printf("end_long\n");
	//printf("\t\t %d dans len_a = %d et len_b = %d\n", (*st_a)->first->data, (*st_a)->len, (*st_b)->len);
	//printf("\t\t %d\n", min);
	//printf("\t\t %d\n", max);
//	ft_merge(st_a, st_b, lst);

//	exit (0);

	return (0);
}

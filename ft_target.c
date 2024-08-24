/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:45:25 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/03 18:09:04 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target(t_list **a, t_list **b, int size)
{
	t_list	*temp;

	temp = *b;
	while (temp)
	{
		set_target(a, temp, size);
		temp = temp->next;
	}
}

void	set_target(t_list **a, t_list *nodo_b, int size)
{
	int		index_b;
	t_list	*min;
	t_list	*max;

	index_b = nodo_b->index;
	max = ft_max(a);
	if (index_b > max->index)
	{
		min = ft_min(a);
		nodo_b->target = min->pos;
	}
	else
		set_target_next(a, nodo_b, size);
}

void	set_target_next(t_list **a, t_list *nodo_b, int size)
{
	int		i;
	t_list	*temp;
	int		index_b;

	index_b = nodo_b->index;
	temp = *a;
	i = 1;
	while (i <= size)
	{
		while (temp)
		{
			if (index_b + i == temp->index)
			{
				nodo_b->target = temp->pos;
				return ;
			}
			temp = temp->next;
		}
		i++;
		temp = *a;
	}
}

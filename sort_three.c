/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:36:52 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/02 15:08:23 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	t_list	*max;
	t_list	*min;

	max = ft_max(a);
	min = ft_min(a);
	ft_position(a);
	if (max->pos == 1)
	{
		ra(a);
		ft_position(a);
	}
	else if (max->pos == 2)
		rra(a);
	ft_position(a);
	if (min->pos == 2)
		sa(a);
	ft_position(a);
}

t_list	*ft_max(t_list **a)
{
	t_list	*temp;
	t_list	*max;

	temp = *a;
	max = *a;
	while (temp)
	{
		if (max->index < temp->index)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_list	*ft_min(t_list **a)
{
	t_list	*temp;
	t_list	*min;

	temp = *a;
	min = *a;
	while (temp)
	{
		if (min->index > temp->index)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

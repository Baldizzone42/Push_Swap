/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totalcost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:34:03 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/02 15:03:23 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	costa(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*aux;
	int		half;
	int		len;

	temp = *b;
	aux = *a;
	half = ((ft_lstsize(aux) / 2) + 1);
	len = ft_lstsize(aux);
	while (temp)
	{
		if (temp->target <= half)
			temp->costa = temp->target - 1;
		else if (temp->target > half)
			temp->costa = temp->target - len -1;
		temp = temp->next;
	}
}

void	costb(t_list **b)
{
	t_list	*temp;
	int		half;
	int		len;

	temp = *b;
	half = ((ft_lstsize(temp) / 2) + 1);
	len = ft_lstsize(temp);
	while (temp)
	{
		if (temp->pos <= half)
			temp->costb = temp->pos - 1;
		else if (temp->pos > half)
			temp->costb = temp->pos - len -1;
		temp = temp->next;
	}
}

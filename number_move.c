/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:41:02 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/03 18:11:41 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	number_move(t_list **a, t_list **b)
{
	t_list	*aux;

	aux = find_cheapest(b);
	if (aux->costa < 0 && aux->costb < 0)
		p_reverse_movements(a, b, aux);
	else if (aux->costa > 0 && aux->costb > 0)
		p_rot_movements(a, b, aux);
	else
		p_mix_movements(a, b, aux);
}

t_list	*find_cheapest(t_list **b)
{
	t_list	*aux;
	t_list	*cheapest;
	int		min;

	aux = *b;
	min = INT_MAX;
	cheapest = ft_cheapest(aux, min);
	return (cheapest);
}

t_list	*ft_cheapest(t_list *aux, int min)
{
	t_list	*cheapest;
	int		sum;
	int		a_cost;
	int		b_cost;

	while (aux)
	{
		a_cost = aux->costa;
		b_cost = aux->costb;
		if (aux->costa < 0)
			a_cost = a_cost * -1;
		if (aux->costb < 0)
			b_cost = b_cost * -1;
		sum = a_cost + b_cost;
		if (sum < min)
		{
			min = sum;
			cheapest = aux;
		}
		aux = aux->next;
	}
	return (cheapest);
}

void	final_move(t_list **a)
{
	t_list	*temp;
	int		i;

	temp = ft_min(a);
	i = temp->costb;
	while (i != 0)
	{
		if (i < 0)
		{
			rra(a);
			i++;
		}
		if (i > 0)
		{
			ra(a);
			i--;
		}
	}
}

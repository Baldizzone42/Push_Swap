/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:21:08 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/03 18:12:42 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_reverse_movements(t_list **a, t_list **b, t_list *node_cheapest)
{
	int	a_cost;
	int	b_cost;

	a_cost = node_cheapest->costa;
	b_cost = node_cheapest->costb;
	while (a_cost < 0 && b_cost < 0)
	{
		rrr(a, b);
		a_cost++;
		b_cost++;
	}
	while (a_cost < 0)
	{
		rra(a);
		a_cost++;
	}
	while (b_cost < 0)
	{
		rrb(b);
		b_cost++;
	}
	pa(b, a);
}

void	p_rot_movements(t_list **a, t_list **b, t_list *node_cheapest)
{
	int	a_cost;
	int	b_cost;

	a_cost = node_cheapest->costa;
	b_cost = node_cheapest->costb;
	while (a_cost > 0 && b_cost > 0)
	{
		rr(a, b);
		a_cost--;
		b_cost--;
	}
	while (a_cost > 0)
	{
		ra(a);
		a_cost--;
	}
	while (b_cost > 0)
	{
		rb(b);
		b_cost--;
	}
	pa(b, a);
}

void	p_mix_movements(t_list **a, t_list **b, t_list *node_cheapest)
{
	int	a_cost;

	a_cost = node_cheapest->costa;
	while (a_cost != 0)
	{
		if (a_cost < 0)
		{
			rra(a);
			a_cost++;
		}
		if (a_cost > 0)
		{
			ra(a);
			a_cost--;
		}
	}
	p_mix_movements2(a, b, node_cheapest);
}

void	p_mix_movements2(t_list **a, t_list **b, t_list *node_cheapest)
{
	int	b_cost;

	b_cost = node_cheapest->costb;
	while (b_cost != 0)
	{
		if (b_cost < 0)
		{
			rrb(b);
			b_cost++;
		}
		else if (b_cost > 0)
		{
			rb(b);
			b_cost--;
		}
	}
	pa(b, a);
}

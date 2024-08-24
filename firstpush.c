/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:06:15 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/03 15:05:34 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firstpush(t_list **a, t_list **b)
{
	int	len;
	int	mitad;
	int	pair;

	pair = 0;
	len = ft_lstsize(*a);
	if (len % 2 != 0)
		pair = 1;
	mitad = ((len / 2) + pair);
	while (len > mitad && len > 3)
	{
		if ((*a)->index <= mitad)
		{
			pb(a, b);
			len--;
		}
		else
			ra(a);
	}
	while (len-- > 3)
		pb(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotatemove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:02:21 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/02 15:22:55 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverserotate(t_list **lst)
{
	t_list	*second_last;
	t_list	*first;
	t_list	*last;

	if (!lst)
		return ;
	if (ft_lstsize(*lst) <= 1)
		return ;
	first = (*lst);
	while ((*lst)->next->next)
		(*lst) = (*lst)->next;
	second_last = (*lst);
	(*lst) = (*lst)->next;
	last = (*lst);
	last->next = first;
	second_last->next = NULL;
}

void	rra(t_list **a)
{
	reverserotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverserotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverserotate(a);
	reverserotate(b);
	write(1, "rrr\n", 4);
}

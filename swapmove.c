/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:52:57 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/02 15:23:42 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*temp;
	t_list	*second;

	temp = *lst;
	second = (*lst)->next;
	temp->next = second->next;
	second->next = temp;
	*lst = second;
}

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkorden.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:35:44 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/03 18:28:53 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkorden(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next)
	{
		if ((temp->value) > (temp->next->value))
			return (0);
		temp = temp->next;
	}
	return (1);
}

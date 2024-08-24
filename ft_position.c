/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:08:14 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/01 20:48:35 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_position(t_list **lst)
{
	int		i;
	t_list	*aux;

	i = 1;
	aux = *lst;
	while (aux)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

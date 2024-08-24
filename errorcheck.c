/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:37:35 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/01 20:32:32 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errorchar(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

int	errornumber(t_list **a)
{
	t_list	*temp;
	t_list	*aux;

	aux = *a;
	temp = *a;
	if (ft_lstsize(*a) == 1)
		return (0);
	while (temp)
	{
		aux = temp->next;
		while (aux)
		{
			if (temp->value == aux->value)
				return (1);
			aux = aux->next;
		}
		temp = temp->next;
	}
	return (0);
}

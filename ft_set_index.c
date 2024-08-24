/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:49:50 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/03 18:05:52 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_list **lst)
{
	int		i;
	int		*tab;
	t_list	*aux;

	tab = malloc (ft_lstsize(*lst) * sizeof(int));
	if (!tab)
		return ;
	aux = *lst;
	i = 0;
	tab[i] = aux->value;
	while (aux)
	{
		tab[i] = aux->value;
		aux = aux->next;
		i++;
	}
	ft_int_sort_tab(tab, i);
	ft_index(tab, lst);
}

void	ft_int_sort_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_index(int *tab, t_list **lst)
{
	t_list	*aux;
	int		i;

	aux = *lst;
	i = 0;
	while (aux)
	{
		if (aux->value == tab[i])
		{
			aux->index = i + 1;
			aux = aux->next;
			i = 0;
		}
		else
			i++;
	}
	free(tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:37:54 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/03 18:13:22 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_stack_start(t_list **a, int argc, char *argv[], int i)
{
	t_list	*node;
	int		z;
	char	**split;

	z = 0;
	while (i <= argc - 1)
	{
		split = ft_split(argv[i], ' ');
		while (split[z])
		{
			node = ft_lstnew(ft_atoll(split[z], a));
			ft_lstadd_back(a, node);
			if (errorchar(split[z]) == 1
				|| node->value > INT_MAX || node->value < INT_MIN)
			{
				free_split(split);
				ft_error(a);
			}
			z++;
		}
		free_split(split);
		i++;
		z = 0;
	}
	return (*a);
}

void	ft_write_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 1)
		return (1);
	while (i <= argc - 1)
	{
		if (argv[i][0] == '\0')
			ft_write_error();
		i++;
	}
	i = 1;
	a = ft_stack_start(&a, argc, argv, i);
	if (errornumber(&a) == 1)
		ft_error(&a);
	if (checkorden(&a) != 1)
		ft_push_swap(&a, &b);
	ft_freestack(&a);
	ft_freestack(&b);
	return (0);
}

void	ft_push_swap(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	ft_set_index(a);
	ft_position(a);
	firstpush(a, b);
	sort_three(a);
	target(a, b, size);
	while (*b)
	{
		ft_position(a);
		ft_position(b);
		target(a, b, size);
		costb(b);
		costa(a, b);
		ft_position(a);
		ft_position(b);
		number_move(a, b);
	}
	ft_position(a);
	costb(a);
	if (checkorden(a) != 1)
		final_move(a);
}

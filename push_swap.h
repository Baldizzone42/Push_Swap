/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:38:09 by jormoral          #+#    #+#             */
/*   Updated: 2024/08/03 18:12:04 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>  
# include <limits.h> 
# include <stdlib.h>
# include <stdio.h>
# include <sys/errno.h>
# include <unistd.h>

typedef struct s_list
{
	long long		value;
	int				pos;
	int				index;
	int				target;
	int				costa;
	int				costb;
	struct s_list	*next;
}	t_list;

//libft
long long	ft_atoll(const char *str, t_list **lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(long long content);
int			ft_lstsize(t_list *lst);
char		**ft_split(const char *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
//Prints
void		ft_print(t_list **lst, char c);
void		ft_print_node(t_list *node);
//positions
void		ft_position(t_list **lst);
// sorts
void		ft_set_index(t_list **lst);
void		ft_int_sort_tab(int *tab, int size);
void		ft_index(int *tab, t_list **lst);

//Movimientos
//   push
void		push(t_list **src, t_list **dst);
void		pa(t_list **b, t_list **a);
void		pb(t_list **a, t_list **b);
// rotate
void		rotate(t_list **lst);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
// reverse
void		reverserotate(t_list **lst);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);
// swap
void		swap(t_list **lst);
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
// first push stack b empuja los mas pequeños
void		firstpush(t_list **a, t_list **b);
// checkear orden stack A
int			checkorden(t_list **a);
//Sort three
void		sort_three(t_list **a);
t_list		*ft_max(t_list **a);
t_list		*ft_min(t_list **a);
// Target
void		target(t_list **a, t_list **b, int size);
void		set_target(t_list **a, t_list *nodo_b, int size);
void		set_target_next(t_list **a, t_list *nodo_b, int size);
// Calculo de costes;
void		costb(t_list **b);
void		costa(t_list **a, t_list **b);
t_list		*find_cheapest(t_list **b);
t_list		*ft_cheapest(t_list *aux, int min);

// Movimientos 
void		number_move(t_list **a, t_list **b);
void		p_reverse_movements(t_list **a, t_list **b, t_list *node_cheapest);
void		p_rot_movements(t_list **a, t_list **b, t_list *node_cheapest);
void		p_mix_movements(t_list **a, t_list **b, t_list *node_cheapest);
void		p_mix_movements2(t_list **a, t_list **b, t_list *node_cheapest);
// Final movement
void		final_move(t_list **a);
// check argumentos.
int			errorchar(char *str);
int			errornumber(t_list **a);
void		ft_error(t_list **a);
// Free stacks
void		ft_freestack(t_list **a);
void		free_split(char **split);
// Main 
void		ft_push_swap(t_list **a, t_list **b);
void		ft_write_error(void);
t_list		*ft_stack_start(t_list **a, int argc, char *argv[], int i);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:17:36 by kbrice            #+#    #+#             */
/*   Updated: 2022/11/10 10:17:38 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
}				t_node;

t_node	*create_node(int number);
t_node	*get_last(t_node *head);
int		ft_stack_size(t_node *head);
void	add_node_front(t_node **stack, t_node *new_node);
void	add_node_back(t_node **stack, t_node *new_node);
void	init_stack(t_node **stack, int argc, char **argv);
int		stack_is_sorted(t_node **stack);
int		get_distance_node(t_node **stack, int index);
void	free_stack(t_node **stack);
void	error_msg(char *msg);
void	ft_free(char **str);
void	check_args(int argc, char **argv);

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

void	push(t_node **stack_from, t_node **stack_dst);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);

int		min(t_node **stack, int number);
void	sort_three(t_node **stack_a);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);

void	radix_sort(t_node **stack_a, t_node **stack_b);
void	simple_sort(t_node **stack_a, t_node **stack_b);
void	index_stack(t_node **stack);

#endif

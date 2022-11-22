/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:15:43 by kbrice            #+#    #+#             */
/*   Updated: 2022/11/10 10:15:52 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}

void	push(t_node **stack_from, t_node **stack_dst)
{
	t_node	*tmp;

	if (ft_stack_size(*stack_from) == 0)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	add_node_front(stack_dst, tmp);
}

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (ft_stack_size(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*head;

	if (ft_stack_size(*stack) < 2)
		return ;
	tail = get_last(*stack);
	head = *stack;
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;
}

void	reverse_rotate(t_node **stack)
{
	t_node	*prev_tail;
	t_node	*tail;

	if (ft_stack_size(*stack) < 2)
		return ;
	prev_tail = *stack;
	while (prev_tail->next->next)
		prev_tail = prev_tail->next;
	tail = prev_tail->next;
	prev_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

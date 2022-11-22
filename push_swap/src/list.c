/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:14:45 by kbrice            #+#    #+#             */
/*   Updated: 2022/11/10 10:14:56 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_node	*create_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node -> number = number;
	new_node -> index = -1;
	new_node -> next = NULL;
	return (new_node);
}

t_node	*get_last(t_node *head)
{
	if (!head)
		return (NULL);
	while (head -> next)
		head = head -> next;
	return (head);
}

void	add_node_front(t_node **stack, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node -> next = *stack;
	*stack = new_node;
}

void	add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!new_node)
		return ;
	if (*stack)
	{
		temp = get_last(*stack);
		temp -> next = new_node;
	}
	else
		*stack = new_node;
}

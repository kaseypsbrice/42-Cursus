/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:16:50 by kbrice            #+#    #+#             */
/*   Updated: 2022/11/10 10:16:58 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	min(t_node **stack, int number)
{
	t_node	*head;
	int		min_index;

	head = *stack;
	min_index = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min_index) && head->index != number)
			min_index = head->index;
	}
	return (min_index);
}

void	sort_three(t_node **stack_a)
{
	if ((*stack_a)->index == min(stack_a, -1)
		&& (*stack_a)->next->index != min(stack_a, min(stack_a, -1)))
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->index == min(stack_a, min(stack_a, -1)))
	{
		if ((*stack_a)->next->index == min(stack_a, -1))
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if ((*stack_a)->next->index == min(stack_a, -1))
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance_node(stack_a, min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance_node(stack_a, min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}

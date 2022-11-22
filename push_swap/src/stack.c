/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:17:05 by kbrice            #+#    #+#             */
/*   Updated: 2022/11/10 10:17:19 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	init_stack(t_node **stack, int argc, char **argv)
{
	t_node	*new;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		new = create_node(ft_atoi(argv[i]));
		add_node_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(argv);
}

int	ft_stack_size(t_node *head)
{
	int	stack_size;

	stack_size = 0;
	while (head)
	{
		stack_size++;
		head = head->next;
	}
	return (stack_size);
}

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

int	stack_is_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head->next)
	{
		if (head->number > head->next->number)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_distance_node(t_node **stack, int index)
{
	t_node	*head;
	int		distance_node;

	distance_node = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance_node++;
		head = head->next;
	}
	return (distance_node);
}

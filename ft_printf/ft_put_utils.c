/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 07:53:18 by kbrice            #+#    #+#             */
/*   Updated: 2022/09/01 10:32:37 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *args, int *len)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ; /* returns null */
	}
	while (args[i] != '\0') /* Otherwise, continue to increment through string */
	{
		ft_putchar_len(args[i], len);
		i++;
	}
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648) /* If it's equal to the minimum value, returns it */
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_len('-', len); /* Puts minus before length when negative number */
		ft_putnbr(n * -1, len); /* Now '-n' is multiplied by -1 to create positive number */
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, len); /* Divides until single digit number */
		ft_putchar_len(n % 10 + '0', len);
	}
}

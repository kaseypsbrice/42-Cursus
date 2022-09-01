/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uxxp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:17:49 by mbishop-          #+#    #+#             */
/*   Updated: 2022/09/01 09:58:02 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p(size_t	p, int *len)
{
	char	str[25];
	int		i;
	char	*base_char;

	base_char = "0123456789abcdef"; /* Hexidecimal format with base 16. 16 symbols or possible digit 
									   values with 6 alphabetical characters.
									   The characters represent decimal values from 10 - 15 in single bits. */
	i = 0;
	write(1, "0x", 2); /* Hexidecimal numbers in text are prefixed with '0x' to indicate it's 
						  a hex number and numeric constant in C. The prefix can differ 
						  depending on the coding language used. */
	(*len) += 2;
	if (p == 0)
	{
		ft_putchar_len('0', len);
		return ; /* Returning 0 if nothing is found */
	}
	while (p != 0)
	{
		str[i] = base_char[p % 16];
		p = p / 16; /* Converting from decimal to hexadecimal */
		i++;
	}
	while (i--)
	{
		ft_putchar_len(str[i], len); /* In the case that %character is not found in the string, it will just print the character. 
										(i--) is a part of an if, else statement within the ft_printf.c file. */
	}
}

void	ft_xx(unsigned int x, int *len, char x_or_x)
{
	char	str[25];
	char	*base_char;
	int		i;

	if (x_or_x == 'X')
		base_char = "0123456789ABCDEF"; /* Determining whether it's uppercase or lowercase for %x or %X specifiers */
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (x != 0)
	{
		str[i] = base_char [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void	ft_u(unsigned int u, int *len)
{
	if (u >= 10)
		ft_u(u / 10, len);
	ft_putchar_len(u % 10 + '0', len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:31:31 by kbrice            #+#    #+#             */
/*   Updated: 2022/09/01 10:31:35 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(char s, va_list *args, int	*len, int *i)

{
	if (s == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (s == 'u')
		ft_u(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_xx(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_xx(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_p(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*i)--; /* If a %specifier that is not declared above is found within the string 
				   it will backtrack and print it after going through the printf function below
				   e.g. %a = a, %%a = %a. */
}

int	ft_printf(const char *s, ...) /* Ellipsis indicates variable number of arguments  */

{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s); /* Enables use of variadic function arguments */
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_check(s[i], &args, &len, &i); /* Checks for %specifiers */
			i++;
		}
		else
		{
			ft_putchar_len((char)s[i], &len); /* If no %specifiers are found, it will print the string as is */
			i++;
		}
	}
	va_end(args); /* Ends use of variadic function arguments */
	return (len);
}

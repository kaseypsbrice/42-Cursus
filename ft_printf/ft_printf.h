/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:31:51 by kbrice            #+#    #+#             */
/*   Updated: 2022/09/01 10:31:55 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int				ft_printf(const char *s, ...);
void			ft_putchar_len(char c, int *len);
void			ft_putnbr(int n, int *len);
void			ft_putstr(char *args, int *len);
void			ft_xx(unsigned int x, int *len, char x_or_x);
void			ft_u(unsigned int u, int *len);
void			ft_p(size_t p, int *len);

#endif

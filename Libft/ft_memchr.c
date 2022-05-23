/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 08:56:36 by kbrice            #+#    #+#             */
/*   Updated: 2022/03/22 08:59:25 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}

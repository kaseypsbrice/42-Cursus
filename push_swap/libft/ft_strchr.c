/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:45:27 by kbrice            #+#    #+#             */
/*   Updated: 2022/03/22 08:22:37 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)

{
	char			*str;
	unsigned char	ch;

	str = (char *)s;
	ch = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

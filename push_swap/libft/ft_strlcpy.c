/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:46:43 by kbrice            #+#    #+#             */
/*   Updated: 2022/03/04 13:50:30 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)

{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dst == 0 || src == 0)
		return (0);
	if (dstsize > 0)
	{
		while (src[j] && j < dstsize -1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

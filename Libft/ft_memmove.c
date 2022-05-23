/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:18:44 by kbrice            #+#    #+#             */
/*   Updated: 2022/03/04 10:22:41 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)

{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = dst;
	temp2 = (unsigned char *)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
		while (len--)
			temp1[len] = temp2[len];
	return (dst);
}

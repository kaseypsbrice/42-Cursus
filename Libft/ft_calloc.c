/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 08:16:06 by kbrice            #+#    #+#             */
/*   Updated: 2022/03/09 14:13:51 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	void	*ptr;

	ptr = malloc(size * count);
	if (ptr == 0)
		return (0);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}

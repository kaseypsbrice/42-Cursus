/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:03:30 by kbrice            #+#    #+#             */
/*   Updated: 2022/03/04 10:30:21 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)

{
	char	*rtn;
	size_t	len;

	len = ft_strlen(s) + 1;
	rtn = malloc(sizeof(char) * len);
	if (!rtn)
		return (0);
	rtn = ft_memcpy(rtn, s, len);
	return (rtn);
}

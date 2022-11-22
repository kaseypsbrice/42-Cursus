/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cturner <cturner@42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:51:19 by cturner           #+#    #+#             */
/*   Updated: 2021/11/16 09:51:24 by cturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_match(char s, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	while (find_match(s1[i], set) == 1)
		i++;
	start = i;
	while (s1[i])
		i++;
	i--;
	while (find_match(s1[i], set) == 1)
		i--;
	len = i - start + 1;
	return (ft_substr(s1, start, len));
}

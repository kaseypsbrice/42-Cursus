/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:17:42 by kbrice            #+#    #+#             */
/*   Updated: 2022/03/22 10:45:01 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)

{
	size_t	begin;
	size_t	end;
	char	*str;

	str = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	if (s1 != 0 && set != 0)
	{
		begin = 0;
		end = ft_strlen(s1);
		while (s1[begin] && ft_strchr(set, s1[begin]))
			begin++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > begin)
			end--;
		str = malloc(sizeof(char) * (end - begin + 1));
		if (str)
			ft_strlcpy(str, &s1[begin], end - begin + 1);
	}
	return (str);
}

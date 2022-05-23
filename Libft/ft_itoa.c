/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:27:09 by kbrice            #+#    #+#             */
/*   Updated: 2022/03/11 14:51:34 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_abs(int n)

{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_int_len(int n)

{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)

{
	int		len;
	int		i;
	char	*res;

	len = ft_int_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (!n)
		res[0] = '0';
	else if (n < 0)
		res[0] = '-';
	i = len - 1;
	while (n)
	{
		res[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i--;
	}
	return (res);
}

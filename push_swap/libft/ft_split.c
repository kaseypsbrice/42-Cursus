/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cturner <cturner@42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:25:03 by cturner           #+#    #+#             */
/*   Updated: 2021/11/16 10:14:51 by cturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	word_count;

	if (!s || !(*s))
		return (0);
	word_count = 0;
	if (s[0] != c)
		word_count++;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			word_count++;
		i++;
	}
	return (word_count);
}

static int	ft_next_word_count(char const *s, char c, int i)
{
	int	word_count;

	word_count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		word_count++;
		i++;
	}
	return (word_count);
}

static char	**ft_free(char **tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb && tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		idx;
	int		word;
	char	**tab;

	idx = 0;
	word = -1;
	tab = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (++word < ft_wordcount(s, c))
	{
		i = 0;
		tab[word] = malloc(ft_next_word_count(s, c, idx) + 1);
		if (!(tab[word]))
			return (ft_free(tab, word));
		while (s[idx] != '\0' && s[idx] == c)
			idx++;
		while (s[idx] != '\0' && s[idx] != c)
			tab[word][i++] = s[idx++];
		tab[word][i] = '\0';
	}
	tab[word] = NULL;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:01:38 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/24 18:01:49 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ftclean(char **split, int i)
{
	int	len;

	len = 0;
	while (len < i)
	{
		free(split[len]);
		len++;
	}
	free (split);
	return (0);
}

static int	countw(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			word++;
		}
	}
	return (word);
}

static void	ftstrcpy(char *p, const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
}

static char	*splitwords(char const *s, char c, int *pos)
{
	int		i;
	int		len;
	char	*p;

	i = *pos;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i + len] != c)
		len++;
	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	ftstrcpy(p, &s[i], c);
	*pos = i + len;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		pos;
	int		words;

	words = countw(s, c);
	split = malloc(sizeof(char *) * words + 1);
	if (s == NULL || split == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < words)
	{
		split[i] = splitwords(s, c, &pos);
		if (split[i] == NULL)
			return (ftclean(split, i));
		i++;
	}
	split[i] = NULL;
	return (split);
}

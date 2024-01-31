/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:45:39 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/24 17:45:47 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftfinal(const char *s, const char *set)
{
	int	i;
	int	cont;

	cont = 0;
	i = ft_strlen(s) - 1;
	printf("%d", i);
	while (i >= 0 && ft_strchr(set, s[i]))
	{
		i--;
		cont++;
	}
	return (cont);
}

static int	ftinicio(const char *s, const char *set)
{
	int	i;

	i = 0;
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		inicio;
	int		final;
	int		size;
	char	*p;

	p = 0;
	if (s1 != 0 && set != 0)
	{
		inicio = ftinicio(s1, set);
		final = ftfinal(s1, set);
		size = ft_strlen(s1) - final - inicio +1;
		p = malloc(sizeof(char) * size);
		if (p == NULL)
			return (NULL);
		ft_strlcpy(p, &s1[inicio], size);
	}
	return (p);
}

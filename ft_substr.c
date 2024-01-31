/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:22 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/24 17:32:29 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ftstrcpy(char *dst, const char *src, unsigned int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i + start];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

    if  (start >= ft_strlen(s))
        {
			p =(char *)malloc(sizeof(char)*1);
			if (p == NULL)
				return (NULL);
			return (p);
		}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	ftstrcpy(p, s , start, len);
	return (p);
}

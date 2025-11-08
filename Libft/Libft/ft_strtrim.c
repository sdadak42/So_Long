/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:50:32 by sdadak            #+#    #+#             */
/*   Updated: 2025/06/25 17:20:58 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim(char a, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_trim(s1[i], set))
	{
		i++;
	}
	while (ft_trim(s1[len - 1], set))
	{
		len--;
	}
	return (ft_substr(s1, i, len - i));
}

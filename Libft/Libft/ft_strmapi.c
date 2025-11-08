/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:45:59 by sdadak            #+#    #+#             */
/*   Updated: 2025/06/29 15:01:19 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;

	i = 0;
	arr = ft_strdup(s);
	if (arr == NULL)
		return (NULL);
	while (arr[i])
	{
		arr[i] = f(i, arr[i]);
		i++;
	}
	return (arr);
}

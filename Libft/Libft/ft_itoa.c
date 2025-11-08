/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:11:18 by sdadak            #+#    #+#             */
/*   Updated: 2025/06/29 15:00:18 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		i = 1;
	while (c != 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

static char	*ft_fill(int n, char *arr, size_t count)
{
	size_t	index;

	index = count;
	arr[index] = '\0';
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
		while (count > 1)
		{
			arr[--count] = n % 10 + '0';
			n = n / 10;
		}
	}
	else
	{
		while (count)
		{
			arr[--count] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = ft_count(n);
	result = (char *)malloc(count + 1);
	if (result == NULL)
		return (NULL);
	return (ft_fill(n, result, count));
}

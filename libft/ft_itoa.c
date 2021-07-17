/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:43:11 by aapollo           #+#    #+#             */
/*   Updated: 2021/07/17 16:08:48 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		size;

	size = count_size(n);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	new[size--] = '\0';
	if (n == 0)
		return (ft_memcpy(new, "0", 2));
	if (n == -2147483648)
		return (ft_memcpy(new, "-2147483648", 13));
	if (n < 0)
	{
		new[0] = '-';
		n *= -1;
	}
	while (n >= 10)
	{
		new[size--] = (n % 10) + '0';
		n /= 10;
	}
	new[size] = n % 10 + '0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:31:31 by aapollo           #+#    #+#             */
/*   Updated: 2020/11/23 20:32:44 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	if (((ch > 47) && (ch < 58)) || ((ch > 64) && (ch < 91))
		|| ((ch > 96) && (ch < 123)))
		return (1);
	return (0);
}
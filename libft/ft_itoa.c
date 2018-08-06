/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:47:34 by pdeguing          #+#    #+#             */
/*   Updated: 2018/07/20 09:35:38 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	int			sign;

	len = ft_intlen(n);
	sign = 1;
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n < 0)
	{
		n = -n;
		len++;
		sign = -1;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = n % 10 + '0';
	while (n /= 10)
		str[--len] = n % 10 + '0';
	if (sign < 0)
		*(str + 0) = '-';
	return (str);
}

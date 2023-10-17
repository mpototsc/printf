/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpototsc <mpototsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:47:27 by mpototsc          #+#    #+#             */
/*   Updated: 2023/10/17 12:20:22 by mpototsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	uintlen(unsigned int n)
{
	size_t	i;

	i = 1;
	n = n / 10;
	if (n == 0)
		return (0);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	size_t		len;
	long int	num;
	char		*str;

	num = n;
	len = uintlen(n);
	str = (char *)malloc(sizeof(char) * (len +1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		str[0] = 48;
	while (num > 0)
	{
		str[len--] = (num % 10) + 48;
		num = num / 10;
	}
	return (str);
}

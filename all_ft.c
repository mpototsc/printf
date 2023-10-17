/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpototsc <mpototsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:48:47 by mpototsc          #+#    #+#             */
/*   Updated: 2023/10/17 12:21:18 by mpototsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(int n)
{
	write(1, &n, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_bignbr(unsigned int n)
{
	char	*str;
	int		i;

	str = ft_uitoa(n);
	i = ft_putstr(str);
	free (str);
	return (i);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	i = ft_putstr(str);
	free (str);
	return (i);
}

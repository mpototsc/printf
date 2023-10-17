/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexdec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpototsc <mpototsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:31:17 by mpototsc          #+#    #+#             */
/*   Updated: 2023/10/17 12:19:52 by mpototsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_strlen(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static void	ft_writehexadec(int num, const char decider)
{
	if (num >= 16)
	{
		ft_writehexadec(num / 16, decider);
		ft_writehexadec(num % 16, decider);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (decider == 'x')
				ft_putchar(num + 'a');
			if (decider == 'X')
				ft_putchar(num + 'A');
		}
	}
}

int	ft_put_hexadec(int num, const char decider)
{
	if (num == '0')
		ft_putchar('0');
	else
		ft_writehexadec(num, decider);
	return (ft_strlen(num));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpototsc <mpototsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:47:22 by mpototsc          #+#    #+#             */
/*   Updated: 2023/10/17 12:24:47 by mpototsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_ptrlen(int ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

static void	ft_write_ptr(int ptr)
{
	if (ptr >= 16)
	{
		ft_write_ptr(ptr / 16);
		ft_write_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr + 'a');
	}
}

int	ft_put_ptr(int ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		len += 5;
	}
	else
	{
		write(1, "0x", 2);
		len += 2;
		ft_write_ptr(ptr);
		len += ft_ptrlen(ptr);
	}
	return (len);
}

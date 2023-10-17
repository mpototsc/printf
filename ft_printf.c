/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpototsc <mpototsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:06:42 by mpototsc          #+#    #+#             */
/*   Updated: 2023/10/17 12:15:00 by mpototsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int	operations(va_list ap, const char decider)
{
	int	count;

	count = 0;
	if (decider == 'c')
		count += ft_putchar(va_arg(ap, int));
	if (decider == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (decider == 'p')
		count += ft_putptr(va_arg(ap, int));
	if (decider == 'd')
		count += putnbr(va_arg(ap, int));
	if (decider == 'i')
		count += putnbr(va_arg(ap, int));
	if (decider == 'u')
		count += ft_put_bignbr(va_arg(ap, unsigned int));
	if (decider == 'x')
		count += ft_put_hexdec(va_arg(ap, int), decider);
	if (decider == 'X')
		count += ft_put_hexdec(va_arg(ap, int), decider);
	if (decider == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		i;
	int		strlen;

	va_start(ap, input);
	i = 0;
	strlen = 0;
	while (input[i])
	{
		while (input[i] != '%' && input[i])
		{
			i++;
			strlen++;
		}
		if (input[i] == '%')
		{
			strlen += operations(ap, input[i + 1]);
		}
		else
			return (strlen);
		return (strlen);
	}
}

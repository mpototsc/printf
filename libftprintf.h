/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpototsc <mpototsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:04:22 by mpototsc          #+#    #+#             */
/*   Updated: 2023/10/17 12:24:14 by mpototsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
int		ft_putchar(int n);
int		ft_putstr(char *s);
int		ft_put_bignbr(unsigned int n);
int		ft_putnbr(int n);
char	*ft_uitoa(unsigned int n);
int		ft_put_ptr(int ptr);
int		ft_put_hexadec(int num, const char decider);

#endif
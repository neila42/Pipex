/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:58:55 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/14 15:15:09 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_value(va_list ap, char c)
{
	if (c == 'c')
		return (print_char(va_arg(ap, int)));
	if (c == 's')
		return (print_str(va_arg(ap, char *)));
	if (c == 'p')
		return (print_ptr(va_arg(ap, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(ap, int)));
	if (c == 'u')
		return (print_unsigned_int(va_arg(ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (print_hex(va_arg(ap, unsigned int), c));
	if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *malice, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, malice);
	while (malice[i])
	{
		if (malice[i] == '%')
		{
			len = len + print_value(ap, malice[i + 1]);
			i = i + 2;
			continue ;
		}
		else
			len = len + print_char(malice[i++]);
	}
	va_end(ap);
	return (len);
}

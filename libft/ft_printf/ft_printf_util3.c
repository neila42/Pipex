/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:57:45 by nmuminov          #+#    #+#             */
/*   Updated: 2022/12/21 16:42:49 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	len_hex(unsigned long l)
{
	int	len;

	len = 0;
	if (l == 0)
		return (1);
	while (l > 0)
	{
		l = l / 16;
		len++;
	}
	return (len);
}

static void	print_hex_recur(unsigned long l, char c)
{
	if (l > 15)
	{
		print_hex_recur(l / 16, c);
		print_hex_recur(l % 16, c);
	}
	else
	{
		if (l >= 10)
		{
			if (c == 'x')
				ft_putchar_fd(l - 10 + 'a', 1);
			else
				ft_putchar_fd(l - 10 + 'A', 1);
		}
		else
			ft_putchar_fd(l + '0', 1);
	}
}

int	print_hex(unsigned long l, char c)
{
	print_hex_recur(l, c);
	return (len_hex(l));
}

int	print_ptr(unsigned long l)
{
	print_str("0x");
	print_hex(l, 'x');
	return (len_hex(l) + 2);
}

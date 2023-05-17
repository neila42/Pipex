/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:54:24 by nmuminov          #+#    #+#             */
/*   Updated: 2022/11/14 14:45:28 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *malice, ...);

int	print_char(char c);
int	print_str(char *str);
int	print_int(int i);
int	print_unsigned_int(unsigned int i);
int	print_hex(unsigned long l, char c);
int	print_ptr(unsigned long l);

#endif

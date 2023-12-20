/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:54:54 by obenchkr          #+#    #+#             */
/*   Updated: 2023/12/20 10:18:13 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dprintf.h>

static int	handle_format(const char format, va_list ap, int fd)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret += ft_putchar_fd(va_arg(ap, int), fd);
	else if (format == 's')
		ret += ft_putstr_fd(va_arg(ap, char *), fd);
	else if (format == 'd' || format == 'i')
		ret += ft_putnbr_fd(va_arg(ap, int), fd);
	else if (format == 'x')
		ret += ft_puthex_fd(va_arg(ap, unsigned int), false, fd);
	else if (format == 'X')
		ret += ft_puthex_fd(va_arg(ap, unsigned int), true, fd);
	else if (format == 'p')
		ret += ft_putptr_fd((uintptr_t) va_arg(ap, void *), fd);
	else if (format == '%')
		ret += ft_putchar_fd('%', fd);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			ret += handle_format(*format, ap, fd);
		}
		else
			ret += ft_putchar_fd(*format, fd);
		format++;
	}
	va_end(ap);
	return (ret);
}

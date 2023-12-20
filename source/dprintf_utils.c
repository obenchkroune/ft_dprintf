/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:54:51 by obenchkr          #+#    #+#             */
/*   Updated: 2023/12/20 10:49:51 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dprintf.h>

int	ft_printchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_printstr_fd(char *s, int fd)
{
	int	ret;

	ret = 0;
	while (*s != '\0')
	{
		ret += ft_printchar_fd(*s, fd);
		s++;
	}
	return (ret);
}

int	ft_printnbr_fd(int n, int fd)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
	{
		ret += ft_printstr_fd("-2147483648", fd);
		return (ret);
	}
	if (n < 0)
	{
		ret += ft_printchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ret += ft_printnbr_fd(n / 10, fd);
		ret += ft_printnbr_fd(n % 10, fd);
	}
	else
		ret += ft_printchar_fd(n + '0', fd);
	return (ret);
}

int	ft_printhex_fd(unsigned int n, bool uppercase, int fd)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += ft_printhex_fd(n / 16, uppercase, fd);
		ret += ft_printhex_fd(n % 16, uppercase, fd);
	}
	else
	{
		if (n < 10)
			ret += ft_printchar_fd(n + '0', fd);
		else
		{
			if (uppercase)
				ret += ft_printchar_fd(n + 'A' - 10, fd);
			else
				ret += ft_printchar_fd(n + 'a' - 10, fd);
		}
	}
	return (ret);
}

int	ft_printptr_fd(uintptr_t n, int fd)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += ft_printptr_fd(n / 16, fd);
		ret += ft_printptr_fd(n % 16, fd);
	}
	else
	{
		if (n < 10)
			ret += ft_printchar_fd(n + '0', fd);
		else
			ret += ft_printchar_fd(n + 'a' - 10, fd);
	}
	return (ret);
}

#ifndef FT_DPRINTF_H

# define FT_DPRINTF_H

#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_dprintf(int fd, const char *format, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_puthex_fd(unsigned int n, bool uppercase, int fd);
int	ft_putptr_fd(uintptr_t n, int fd);

#endif
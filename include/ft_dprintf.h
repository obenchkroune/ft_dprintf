#ifndef FT_DPRINTF_H

# define FT_DPRINTF_H

#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_dprintf(int fd, const char *format, ...);
int	ft_printchar_fd(char c, int fd);
int	ft_printstr_fd(char *s, int fd);
int	ft_printnbr_fd(int n, int fd);
int	ft_printhex_fd(unsigned int n, bool uppercase, int fd);
int	ft_printptr_fd(uintptr_t n, int fd);

#endif
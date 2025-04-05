
#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>

# define UNICODE_MARKER "é"

void	processor(int sig);
void	send_char(int pid, char c);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int x);
void	ft_print_finish_mesage(int *i, int *pid);
void	ft_print_pid_client(int pid_client);
char	*ft_itoa(int n);
void	pid_client_checker(int sig);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
void	*ft_memcpy(void	*dest, const void	*src, size_t	n);
int		character_check(char c);
char	*ft_unicode_checker(char *message);
char	*ft_strcpy(char *dest, const char *src);

#endif

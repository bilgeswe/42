
#include "minitalk.h"

void	decode_bit(int sig, char *c, int *bit)
{
	if (sig == SIGUSR1)
		*c |= 1 << *bit;
	(*bit)++;
}

void	processor(int sig)
{
	static char	c;
	static int	bit;
	static int	i;
	static int	pid;

	decode_bit(sig, &c, &bit);
	i++;
	if (bit == 8)
	{
		if (c == '\0')
			ft_print_finish_mesage(&i, &pid);
		else if (i < 88)
		{
			if (c != 'p')
				pid = pid * 10 + (c - '0');
		}
		else
			character_check(c);
		bit = 0;
		c = 0;
	}
	if (i >= 87)
		kill(pid, SIGUSR1);
}

int	character_check(char c)
{
	if ((unsigned char)c <= 127)
		write(1, &c, 1);
	else
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	return (1);
}

void	ft_print_finish_mesage(int *i, int *pid)
{
	kill(*pid, SIGUSR1);
	write(1, "\nPID:\n", 6);
	ft_putnbr(*pid);
	write(1, "\nMessage received\n", 18);
	*i = 0;
	*pid = 0;
}

int	main(int ac, char **avg)
{
	(void)avg;
	if (ac != 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	write(1, "\n", 1);
	if (signal(SIGUSR1, processor) == SIG_ERR
		|| signal(SIGUSR2, processor) == SIG_ERR)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (1);
}

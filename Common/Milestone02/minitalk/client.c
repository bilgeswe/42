
#include "minitalk.h"

volatile sig_atomic_t	g_sign;

void	pid_client_checker(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
		g_sign = 1;
}

void	send_char(int pid, char c)
{
	static int	i;
	int			bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (i > 111)
		{
			if (i == 112)
				usleep(3000);
			while (!g_sign)
				;
			g_sign = 0;
		}
		else
			usleep(1000);
		bit++;
		i++;
	}
	return ;
}

void	send_pid_str(char *pid_client_str, char *message, int pid)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (*pid_client_str)
		{
			send_char(pid, *pid_client_str);
			pid_client_str++;
		}
		else
			send_char(pid, 'p');
		i++;
	}
	send_char(pid, '\n');
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(pid, '\0');
}

void	ft_print_pid_client(int pid_client)
{
	write(1, "PID:\n", 5);
	ft_putnbr(pid_client);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;
	char	*pid_client_str;

	if (ac != 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	message = av[2];
	message = ft_unicode_checker(message);
	ft_print_pid_client(getpid());
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1 || pid > 4194304 || pid == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	pid_client_str = ft_itoa(getpid());
	if (!pid_client_str)
		exit (1);
	signal(SIGUSR1, pid_client_checker);
	send_pid_str(pid_client_str, message, pid);
	free (pid_client_str);
	return (1);
}

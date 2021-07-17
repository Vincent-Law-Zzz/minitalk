#include "minitalk.h"

int	g_count[2];

int	ft_pow(int n, int pow)
{
	int	res;

	res = n;
	if (pow == 0)
		return (1);
	pow--;
	while (pow)
	{
		res = res * n;
		pow--;
	}
	return (res);
}

void	my_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_count[1] += ft_pow(2, g_count[0]);
		g_count[0] += 1;
	}
	if (signum == SIGUSR2)
		g_count[0] += 1;
	if (g_count[0] == 7)
	{
		write(1, &g_count[1], 1);
		if (g_count[1] == 0)
			write(1, "\n", 1);
		g_count[1] = 0;
		g_count[0] = 0;
	}
}

int	main(void)
{
	char	*pid;

	g_count[0] = 0;
	g_count[1] = 0;
	pid = ft_itoa(getpid());
	write(1, "pid ", 4);
	write(1, pid, sizeof(pid) - 1);
	write(1, "\n", 1);
	free(pid);
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
		pause();
	return (0);
}

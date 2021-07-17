#include "minitalk.h"

void	ft_send_ch(int pid, int ch)
{
	int	i;
	int	er;

	i = 0;
	er = 0;
	while (i < 7)
	{
		if (ch % 2 == 1)
			er = kill(pid, SIGUSR1);
		if (ch % 2 == 0)
			er = kill(pid, SIGUSR2);
		ch = ch / 2;
		i++;
		usleep(100);
	}
	if (er == -1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		i;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		ft_send_ch(pid, (int)str[i]);
		i++;
	}
	ft_send_ch(pid, '\n');
	return (0);
}


#include "aux.h"
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	send_str(int server_pid, char const *str);

int	main(int argc, char *argv[])
{
	int				server_pid;
	int				i;
	wchar_t			*wc_input;
	char const		*str;

	if (argc != 3)
		return (1);
	server_pid = atoi(argv[1]);
	str = argv[2];
	if (argv[1][0] == 'L' && argv[1][1] == '\"')
	{
		i = 0;
		while (argv[1])
			i++;
		wc_input = malloc((i + 1) * sizeof(wchar_t));
		if (wc_input == 0)
			return (1);
		wcscpy(wc_input, (wchar_t *) &argv[1][2]);
		// send_str(server_pid, "w");
		// send_str(server_pid, wc_input);
		free(wc_input);
	}
	else
	{
		//printf("%s\n", str);
		send_str(server_pid, str);
	}
	return (0);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	send_str(int pid, char const *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
		}
	}
	printf("Accepted\n");
}

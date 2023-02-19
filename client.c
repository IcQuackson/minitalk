
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
	//int				i;
	//wchar_t			*wc_input;
	char const		*str;

	if (argc != 3)
		return (1);
	server_pid = atoi(argv[1]);
	str = argv[2];
	if (argv[1][0] == '\"' && argv[1][1] == 'U')
	{
		printf("unicode\n");
		/* i = 0;
		while (argv[1])
			i++;
		wc_input = malloc((i + 1) * sizeof(wchar_t));
		if (wc_input == 0)
			return (1);
		wcscpy(wc_input, (wchar_t *) &argv[1][2]);
		// send_str(server_pid, "w");
		// send_str(server_pid, wc_input);
		free(wc_input); */
	}
	else
	{
		//printf("%s\n", str);
		send_str(server_pid, str);
	}
	return (0);
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		write(1, "Aknowledged!\n", 13);
}

void	send_str(int pid, char const *str)
{
	int					i;
	char				c;
	struct sigaction	sa;

	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
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
			//printf("%d", c >> i & 1);
			usleep(500);
		}
	}
	while (++i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(600);
	}
}
//"My name is Yoshikage Kira. I'm 33 years old. My house is in the northeast section of Morioh, where all the villas are, and I am not married. I work as an employee for the Kame Yu department stores, and I get home every day by 8 PM at the latest. I don't smoke, but I occasionally drink. I'm in bed by 11 PM, and make sure I get eight hours of sleep, no matter what. After having a glass of warm milk and doing about twenty minutes of stretches before going to bed, I usually have no problems sleeping until morning. Just like a baby, I wake up without any fatigue or stress in the morning. I was told there were no issues at my last check-up. I'm trying to explain that I'm a person who wishes to live a very quiet life. I take care not to trouble myself with any enemies, like winning and losing, that would cause me to lose sleep at night. That is how I deal with society, and I know that is what brings me happiness. Although, if I were to fight I wouldn't lose to anyone."
//ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
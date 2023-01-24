

#include <signal.h>
#include <wchar.h>
#include <unistd.h>
#include <stdio.h>

/* 
int	g_letter;
int		bit_index;

void	ft_printchar(int c)
{
	write(1, &c, 1);
}

void	sigusr1_handler(int num)
{
	(void) num;
	g_letter = g_letter & ~(1 << (bit_index % 8));
	write(1, "bit=", 5);
	ft_printchar('0'+ bit_index);
	write(1, "\n", 1);
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &g_letter, 1);
		//printf("%d\n", g_letter);
		bit_index = 0;
	}
}



void	sigusr2_handler(int signal_num)
{
	g_letter = g_letter | (1 << (bit_index % 8));
	write(1, "bit=", 5);
	ft_printchar('0'+ bit_index);
	write(1, "\n", 1);
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &g_letter, 1);
		//printf("%d\n", g_letter);
		bit_index = 0;
	}
} */

/* #define BUFFER_SIZE 20

struct ring_buffer {
    unsigned char buffer[BUFFER_SIZE];
    int head;
    int tail;
};

struct ring_buffer rb = {{0}, 0, 0};

void signal_handler(int signal_num)
{
    unsigned char c = (signal_num == SIGUSR2);
    if ((rb.tail + 1) % BUFFER_SIZE == rb.head) {
        //printf("Buffer is full, data will be overwritten\n");
    }
    rb.buffer[rb.tail] = c;
    rb.tail = (rb.tail + 1) % BUFFER_SIZE;
    if (rb.tail == rb.head) {
        unsigned char data = 0;
        for (int i = 0; i < BUFFER_SIZE; i++) {
            data |= rb.buffer[i];
            data <<= 1;
        }
        write(1, &data, 1);
        rb.tail = 0;
        rb.head = 0;
    }
} */


/* void	signal_handler(int signal_num)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (signal_num == SIGUSR2);

	if (++i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
} */

void	signal_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}


/* static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;

	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
} */


int main()
{
	/* struct sigaction	sa1;
	struct sigaction	sa2;

	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = SA_NODEFER;
	sa1.sa_handler = sigusr1_handler;
	sigemptyset(&sa2.sa_mask);
	sa2.sa_flags = SA_NODEFER;
	sa2.sa_handler = sigusr2_handler;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	g_letter = 0; */

/*
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	*/

	struct sigaction sa;
	sa.sa_handler = &signal_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
//
	printf("pid = %d\n", getpid());
	while (1)
	{
		usleep(100);
	}
	return 0;
}

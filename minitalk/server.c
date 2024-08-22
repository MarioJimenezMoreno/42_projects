#include "minitalk.h"

static char binary_to_char(int signal, int print)
{
	static int	i;
	static int	number;
	static int	letter;

	if (i == 0)
	{
		letter = '\0';
		number = 1;
	}
	if (signal == SIGUSR1)
		letter += number;
	number *= 2;
	i++;
	if (i == 8)
	{
		if (print == 1)
			write(1, &letter, 1);
		i = 0;
		return (letter);
	}
	return (0);
}

static  void	handle_info(int signal, int* null_count, int* ptr)
{
	char	temp;

	temp = binary_to_char(signal, 0);
	if (temp == ' ')
		*null_count += 1;
	else if (temp >= '0' && temp <= '9')
		*ptr = ((*ptr) * 10) + (temp - '0');
}

static void	handle_msg(int signal, int* null_count, int* len, int* pid)
{
	char temp;

	temp = binary_to_char(signal, 1);
	if (temp)
		*len -= 1;
	if (*len == 0)
	{
		write(1,"\n", 1);
		kill(*pid,SIGUSR1);
		*pid = 0;
	}
}

static void	handle_signal(int signal)
{
	static int	len;
	static int	pid;
	static int	null_count;

	if (pid == 0 || null_count == 3)
	{
		len = 0;
		null_count = 0;
		pid = 0;
	}
	if (null_count == 0)
		handle_info(signal, &null_count, &pid);
	else if (null_count == 1)
		handle_info(signal, &null_count, &len);
	else if (null_count == 2)
		handle_msg(signal, &null_count, &len, &pid);
	fflush(stdout);
}


int	main()
{
	printf("Servidor iniciado || PID: %d\n______________________________\nMensajes:\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause ();
	}
	return (0);
}

#include "minitalk.h"

char* sent;

static void	free_ptr(char** ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static void	check_received(int signal)
{
	printf("MESSAGE RECEIVED.\n");
	kill(getpid(),SIGKILL);
}

static int	send_signals(int pid, char** word)
{
	int	i;
	int	j;

	i = 0;
	while (word[i])
	{
		j = 7;
		while (j >= 0)
		{
			if(word[i][j] == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
	return (1);
}

static void	string_to_binary(int letter, char* binary, int i)
{
	while (letter)
	{
		binary[7 - i] = letter % 2;
		string_to_binary(letter / 2, binary, i + 1);
		break ;
	}
}

static char**	encrypt(char* msg, int len)
{
	char** word;
	int	i;

	i = 0;
	word = (char **)malloc(sizeof(char *) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = ft_calloc(9, sizeof(int));
		if (!word[i])
			return (NULL);
		word[i][8] = '\0';
		i++;
	}
	i = 0;
	while (msg[i])
	{
		string_to_binary(msg[i], word[i], 0);
		i++;
	}
	fflush(stdout);
	word[len] = NULL;
	return (word);
}

static void client(char* pid, char* msg)
{
	char*	len;
	char**	e_msg;
	char**	e_len;
	char**	e_pid;

	len = ft_strjoin(ft_itoa(ft_strlen(msg)), " ");
	e_pid = encrypt(ft_strjoin(ft_itoa(getpid()), " "), ft_strlen(ft_itoa(getpid())) + 1);
	e_len = encrypt(len, ft_strlen(len));
	e_msg = encrypt(msg, ft_strlen(msg));
	send_signals(ft_atoi(pid), e_pid);
	send_signals(ft_atoi(pid), e_len);
	send_signals(ft_atoi(pid), e_msg);
	return (free_ptr(e_pid), free_ptr(e_len), free_ptr(e_msg), free(len));
}

int main(int argc, char** argv)
{
	if (argc != 3)
		return (0);
	client(argv[1], argv[2]);
	while (1)
	{
		signal(SIGUSR1,check_received);
		pause ();
	}
	return (0);
}

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int i = 0;

void	receive_str(int sinal)
{
	char	*str;

	if (sinal == 30)
	{
		str[i] = '0';
		i++;
	}
	else if (sinal == 31)
	{
		str[i] = '1';
		i++;
	}
	if (i == 8)
	{
		str[i++] = '\0';
		printf("%s\n", str);
		i = 0;
	}
}

int main()
{ 
	printf("\nServer PID: %d\n", getpid());
	signal(SIGUSR1, receive_str);
	signal(SIGUSR2, receive_str);
	while(1);
}

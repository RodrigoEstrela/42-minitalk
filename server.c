#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include"libft.h"

int i = 0;

int decoder(char *str)
{
	int a;
	int res;

	a = 8;
	res = 0;
	while (a >= 0)
	{
		if (str[a] == '1')
			res += 1 * ft_recursive_power(2, (7 - a));
		a--;
	}
//	printf("%c\n", res);
	return (res);
}

void	receive_str(int sinal)
{
	char	*str;
	int	cena;

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
		str[i] = '\0';
		cena = decoder(str);
		printf("%c\n", cena);
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

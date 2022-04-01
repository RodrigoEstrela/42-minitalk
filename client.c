#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include"libft.h"

int	*binvert(int c)
{
	int *arrayBin;
	int i = 7;
	arrayBin = malloc(8*sizeof(int));

	while((c) != 0)
	{
		arrayBin[i] = c % 2;
		c /= 2;
		i--;
	}
	while(i >= 0)
		arrayBin[i--] = 0;
	
	for (i=0; i<8; i++)
		printf("%d", arrayBin[i]);
	return(arrayBin);
}

void	SigSend(int *array,	int pid)
{
	int	i = 0;
	while(i<8)
	{
		if (array[i] == 0)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else if (array[i] == 1)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	free(array);
}

int main(int ac, char **av)
{
	int pid = atoi(av[1]);
	int	i=0;
	while(av[2][i] != '\0')
	{
		int input = ft_isalnum((int)(av[2][i]));
		SigSend(binvert(input), pid);
		printf(" ");
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:06:41 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/05 17:28:17 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include"libft.h"

int	*binvert(int c)
{
	int	*array_bin;
	int	i;

	i = 7;
	array_bin = malloc(8 * sizeof(int));
	while (c != 0)
	{
		array_bin[i] = c % 2;
		c /= 2;
		i--;
	}
	while (i >= 0)
		array_bin[i--] = 0;
	return (array_bin);
}

void	sig_send(int *array,	int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (array[i] == 0)
		{
			kill(pid, SIGUSR1);
			usleep(80);
		}
		else if (array[i] == 1)
		{
			kill(pid, SIGUSR2);
			usleep(80);
		}
		i++;
	}
	free(array);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	input;

	if (ac != 3)
	{
		ft_printf("\e[1;3;31m[Server pid] and [Input string] Required! 👎\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i] != '\0')
	{
		input = ft_isprint((int)(av[2][i]));
		sig_send(binvert(input), pid);
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(80);
	}
}

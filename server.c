/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:06:50 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/05 17:26:01 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include"libft.h"

int	g_i = 0;

int	decoder(unsigned char *str)
{
	int	a;
	int	res;

	a = 7;
	res = 0;
	while (a >= 0)
	{
		if (str[a] == '1')
			res += 1 * ft_recursive_power(2, (7 - a));
		else
			res += 0;
		a--;
	}
	return (res);
}

void	receive_str(int sinal)
{
	unsigned char	str[9];
	int				to_print;

	if (sinal == 30)
		str[g_i++] = '0';
	else if (sinal == 31)
		str[g_i++] = '1';
	if (g_i == 8)
	{
		str[g_i] = '\0';
		if (str[0] == '1')
		{
			g_i = write(1, "\n", 1) - 1;
			return ;
		}
		to_print = decoder(str);
		write(1, &to_print, 1);
		g_i = 0;
	}
}

int	main(void)
{
	ft_printf("\n\e[1;3;35m=======================\n");
	ft_printf("\n\e[1;3;33m Server pid: \e[1;3;34m %d", getpid());
	ft_printf("\n\e[1;3;35m=======================\n\n\e[0m");
	signal(SIGUSR1, receive_str);
	signal(SIGUSR2, receive_str);
	while (1)
		pause();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:51:07 by fayan             #+#    #+#             */
/*   Updated: 2022/03/15 17:13:37 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	takesignal(int signal)
{
	static char	c;
	static int	okunan_byte;

	if (signal == SIGUSR1)
		c |= 1;
	if (++okunan_byte == 8)
	{
		okunan_byte = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

void	pidyazdir(int a)
{
	if (a > 9)
	{
		pidyazdir(a / 10);
		pidyazdir(a % 10);
	}
	if (a <= 9)
	{
		write(1, &"0123456789"[a], 1);
	}
}

int	main(void)
{
	char	*str;

	str = "server pid = ";
	while (*str)
		write(1, str++, 1);
	pidyazdir(getpid());
	write (1, "\n", 1);
	signal(SIGUSR1, takesignal);
	signal(SIGUSR2, takesignal);
	while (1)
	{
		pause();
	}
	return (0);
}

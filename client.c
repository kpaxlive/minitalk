/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:44:19 by fayan             #+#    #+#             */
/*   Updated: 2022/03/15 16:45:04 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_gonder(int pid, char *str)
{
	int		i;
	char	c;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 8;
		c = str[i];
		while (j--)
		{
			if (c >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		i++;
	}
	j = 8;
	while (j--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	ft_atoi(char *x)
{
	int	sayi;
	int	i;

	i = 0;
	sayi = 0;
	while (x[i] != '\0')
	{
		sayi = (x[i] - '0') + (sayi * 10);
		i++;
	}
	return (sayi);
}

int	main(int argc, char **argv)
{
	int		b;
	char	*a;

	a = "İki arguman girmelisin!\n";
	b = 0;
	if (argc != 3)
	{
		while (a[b] != '\0')
		{
			write(1, &a[b], 1);
			b++;
		}
		return (0);
	}
	ft_gonder(ft_atoi(argv[1]), argv[2]);
	ft_gonder(ft_atoi(argv[1]), "\n");
	return (0);
}

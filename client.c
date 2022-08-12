/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:00:33 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/12 09:56:13 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_catch(pid_t pid, int c)
{
	int				n;
	int				byte;
	unsigned char	msg;

	n = 128;
	byte = 8;
	msg = c;
	while (byte--)
	{
		if (msg / n)
		{
			msg -= n;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(150);
			n /= 2;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		message = av[2];
		while (message[i])
		{
			ft_catch(pid, message[i]);
			i++;
		}
	}
	else
	{
		ft_printf("Wrong !!!");
		return (0);
	}
}

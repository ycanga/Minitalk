/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:00:31 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/14 00:34:03 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_bit(int x)
{
	static int	bit = 7;
	static int	set = 0;

	set += x << bit;
	if (bit == 0)
	{
		write(1, &set, 1);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void	sgl_catch(int x)
{
	if (x == SIGUSR1)
	{
		set_bit(1);
	}
	else if (x == SIGUSR2)
	{
		set_bit(0);
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %u\n", pid);
	signal(SIGUSR1, sgl_catch);
	signal(SIGUSR2, sgl_catch);
	while (1)
		pause();
}

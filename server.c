/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:00:31 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/06 15:00:32 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void *print(void)
{
    printf("sinyal alındı!\n");
    return NULL;
}

int main()
{
    int pid;

    pid = getpid();
    printf("%d\n", pid);
    signal(SIGUSR1, (void *)print);
    while(1)
        pause();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:42:57 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/04 19:47:45 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;
	int rv;

	rv = 0;
	switch(pid = fork())
	{
		case -1:
			perror("fork failure"); /*произошла ошибка*/
			exit(1);
		case 0:
			printf("CHILD: This is child process\n");
			printf("CHILD: Mine PID is -- %d\n", getpid());
			printf("CHILD: Parent process PID is -- %d\n", getppid());
			printf("CHILD: Input return code:\n");
			scanf("%d", &rv);
			printf("CHILD: Thanks, now exit. Bye!\n");
			exit(rv);
		default:
			printf("PARENT: This is parrent process, hello=)\n");
			printf("PARENT: This my PID -- %d\n", getpid());
			printf("PARENT: This is PID of my child -- %d\n", pid);
			printf("PARENT: Now i gonna wait for my child exit()...\n");
			wait(NULL);
			printf("PARENT: Here's my child exit code status digit -- %d\n", WEXITSTATUS(rv));
			printf("PARENT: Job's done. Have a nice day:)\n");
	}
	return (0);
}

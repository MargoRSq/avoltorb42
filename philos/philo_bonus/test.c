# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

int main()
{
	pid_t pid;
	int	count = 10;
	int pids[10];
	int i = 0;

	printf("before fork - %d\n", getpid());
	while (++i < count)
	{
		pid = fork();
		if (pid == 0)
		{
			usleep(300000*i);
			printf("child! - %d\n", getpid());
			exit(0);
		}
		pids[i] = pid;
		printf("arr pid - %d\n", pids[i]);
	}
	while (i-- > 0)
		waitpid(pids[i - 1], NULL, 0);
	printf("after forks - %d\n", getpid());
}
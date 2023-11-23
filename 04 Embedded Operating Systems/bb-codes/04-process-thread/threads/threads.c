#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include <pthread.h>

pthread_t thread1;
pthread_t thread2;

void thread1_func(void);
void thread2_func(void);

int main()
{
	pthread_attr_t attr;
	int status;

	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, 1024*1024);

	fprintf(stderr, "main: creating thread-1\n");
	status = pthread_create(&thread1, &attr, (void *)&thread1_func, NULL);
	if (status!=0)
	{
		perror("Failed to create thread-1");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "main: creating thread-2\n");
	status = pthread_create(&thread2, &attr, (void *)&thread2_func, NULL);
	if (status!=0)
	{
		perror("Failed to create thread-2");
		exit(EXIT_FAILURE);
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	fprintf(stderr, "main: all threads done!\n");

	return EXIT_SUCCESS;
}

void thread1_func()
{
	int sleep_time = 10;

	fprintf(stderr, "\tthread-1: PID[%ld] and TID[%lu]\n", (long)getpid(), pthread_self());
	while(sleep_time)
	{
		fprintf(stderr, "\tthread-1[%d]\n", sleep_time);
		sleep(1);
		sleep_time--;
	}

	fprintf(stderr, "\tthread-1: exiting\n");
	pthread_exit(NULL);
}

void thread2_func()
{
	int sleep_time = 15;

	fprintf(stderr, "\tthread-2: PID[%ld] and TID[%lu]\n", (long)getpid(), pthread_self());
	while(sleep_time)
	{
		fprintf(stderr, "\t\tthread-2[%d]\n", sleep_time);
		sleep(1);
		sleep_time--;
	}

}


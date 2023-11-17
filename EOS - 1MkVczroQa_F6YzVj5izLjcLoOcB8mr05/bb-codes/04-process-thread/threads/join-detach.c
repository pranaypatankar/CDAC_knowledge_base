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
	int status;

	pthread_attr_t attr;
	
	pthread_attr_init(&attr);
        pthread_attr_setstacksize(&attr, 1024*1024);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	
	char thread_state[10] = {0};
	int detach_state;

	pthread_attr_getdetachstate(&attr, &detach_state);
        sprintf(thread_state, "%s", (detach_state == PTHREAD_CREATE_DETACHED) ? "DETACHED" :
               (detach_state == PTHREAD_CREATE_JOINABLE) ? "JOINABLE" :
               "???");
        fprintf(stderr, "main: creating thread-1 in state: %s\n", thread_state);
        status = pthread_create(&thread1, &attr, (void *)&thread1_func, NULL);
        if (status!=0)
        {
                perror("Failed to create thread-1");
                exit(EXIT_FAILURE);
        }

	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	
	pthread_attr_getdetachstate(&attr, &detach_state);
        sprintf(thread_state, "%s", (detach_state == PTHREAD_CREATE_DETACHED) ? "DETACHED" :
               (detach_state == PTHREAD_CREATE_JOINABLE) ? "JOINABLE" :
               "???");
        fprintf(stderr, "main: creating thread-2 in state: %s\n", thread_state);
        status = pthread_create(&thread2, &attr, (void *)&thread2_func, NULL);
        if (status!=0)
        {
                perror("Failed to create thread-2");
                exit(EXIT_FAILURE);
        }

        int ret;
	ret = pthread_join(thread1, NULL);
	if (ret!=0)
	{
		fprintf(stderr, "main: Error joining thread-1\n");
		exit (EXIT_FAILURE);
	}
	else
		fprintf(stderr, "main: thread-1 joined!\n");

        ret = pthread_join(thread2, NULL);
	if (ret!=0)
	{
		fprintf(stderr, "main: Error joining thread-2\n");
		exit (EXIT_FAILURE);
	}
	else
		fprintf(stderr, "main: thread-2 joined\n");

	return EXIT_SUCCESS;
}

void thread1_func()
{
        int sleep_time = 10;

        while(sleep_time)
        {
                fprintf(stderr, "\tthread-1[%d]\n", sleep_time);
                sleep(1);
                sleep_time--;
        }
}

void thread2_func()
{
        int sleep_time = 15;

        while(sleep_time)
        {
                fprintf(stderr, "\t\tthread-2[%d]\n", sleep_time);
                sleep(1);
                sleep_time--;
        }
}



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

char g_data[128];
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *consumer(void *arg)
{
	while (1) {
		pthread_mutex_lock(&mutex);
		while (strlen(g_data) == 0)
			pthread_cond_wait(&cond, &mutex);

		/* Got data */
		printf("Consumer-> Got:: %s\n", g_data);
		/* Truncate to null string again */
		g_data[0] = 0;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void *producer(void *arg)
{
	int i = 0;

	while (1) {
		sleep(1);
		pthread_mutex_lock(&mutex);
		sprintf(g_data, "%d", i);
		printf("Producer-> Put:: %s\n", g_data);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
		i++;
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t producer_thread;
	pthread_t consumer_thread;

	pthread_create(&producer_thread, NULL, producer, NULL);
	pthread_create(&consumer_thread, NULL, consumer, NULL);

	/* Wait for both threads to finish */
	pthread_join(producer_thread, NULL);
	pthread_join(consumer_thread, NULL);

	return 0;
}

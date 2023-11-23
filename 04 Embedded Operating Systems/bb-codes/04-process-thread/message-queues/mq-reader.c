#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>

#include "mq.h"

int main()
{
	mqd_t mq;
	
	mq = mq_open(MQ_NAME, O_RDONLY | O_NONBLOCK);
	if ( (mqd_t)-1 == mq)
	{
		perror("Error opening mq");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "MQ: %s opened\n", MQ_NAME);
	
	struct mq_attr attr;
	mq_getattr(mq, &attr);

	char *buf = calloc((attr.mq_msgsize+1), sizeof(char));
	while(1)
	{
		unsigned int prio;
		memset(buf, 0, attr.mq_msgsize);
		ssize_t ret = mq_receive(mq, buf, attr.mq_msgsize, &prio);
		if (-1 == ret)
		{
			if (EAGAIN == errno)
			{
				printf("Queue empty!\n");
				break;
			}
			else
			{
				perror("mq_receive error");
				exit(EXIT_FAILURE);
			}
		}	
		printf("Received message: \"%s\" with prio[%d]\n", buf, prio);
	}

	free(buf);

	fprintf(stderr, "Closing MQ: %s\n", MQ_NAME);
	mq_close(mq);

	fprintf(stderr, "Unlinking MQ: %s\n", MQ_NAME);
	mq_unlink(MQ_NAME);

	exit(EXIT_SUCCESS);
}
	

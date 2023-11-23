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
	struct mq_attr attr;

	/* initialize the queue attributes */
    	attr.mq_flags = O_CREAT | O_EXCL | O_NONBLOCK;
    	attr.mq_maxmsg = MQ_MAX_MSGS;
    	attr.mq_msgsize = MQ_MSG_SIZE;
    	attr.mq_curmsgs = 0;

	mq = mq_open(MQ_NAME, O_CREAT | O_WRONLY, 0644, &attr);
	if ( (mqd_t)-1 == mq)
	{
		perror("Error creating mq");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "MQ: %s created\n", MQ_NAME);

	/* Messages */
#define NUM_MSGS	(3)
	char *messages[NUM_MSGS] = 
	{
		"Message-1: apple",
		"Message-2: banana",
		"Message-3: pineapple"
	};

	int prio = 0;
	for (int i=0;i<NUM_MSGS;i++)
	{
		printf("Sending message: \"%s\" with prio[%d]\n", messages[i], prio);
		mq_send(mq, messages[i], strlen(messages[i]), prio);
		prio++;	
	}


	fprintf(stderr, "Closing MQ: %s\n", MQ_NAME);
	mq_close(mq);

	//fprintf(stderr, "Unlinking MQ: %s\n", MQ_NAME);
	//mq_unlink(MQ_NAME);
	//
	exit(EXIT_SUCCESS);
}
	

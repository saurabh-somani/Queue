#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_node
{
	void *pData;
	struct queue_node *next;
}QUEUE_NODE;

typedef struct
{
	int count;
	QUEUE_NODE *front;
	QUEUE_NODE *rear;
}QUEUE;

//QUEUE FUNCTIONS
QUEUE* 	createQueue();							//CREATE QUEUE
bool 	enqueue(QUEUE *queue, void *pDataIn);	//ENQUEUE
void* 	dequeue(QUEUE *queue);					//DEQUEUE
void* 	queueFront(QUEUE *queue);				//WHAT'S THE QUEUE FRONT?
void* 	queueRear(QUEUE *queue);				//WHAT'S THE QUEUE REAR?
bool 	emptyQueue(QUEUE *queue);				//IS QUEUE EMPTY?
bool 	fullQueue(QUEUE *queue);				//IS QUEUE FULL?
int 	queueCount(QUEUE *queue);				//WHAT'S THE QUEUE COUNT?
QUEUE* 	destroyQueue(QUEUE *queue);				//DESTROY QUEUE



QUEUE *createQueue()
{
	QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE));

	if (queue)
	{
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
	}

	return queue;
}

bool enqueue(QUEUE *queue, void *pDataIn)
{
	QUEUE_NODE *newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

	if (!newPtr)
	{
		return false;
	}

	newPtr->pData = pDataIn;
	newPtr->next = NULL;

	if (queue->count == 0)
	{
		queue->front = newPtr;
	}
	else
	{
		queue->rear->next = newPtr;
	}

	(queue->count)++;
	queue->rear = newPtr;

	return true;
}

void *dequeue(QUEUE *queue)
{
	void *pDataOut;

	if (queue->count == 0)
	{
		pDataOut = NULL;
	}
	else
	{
		QUEUE_NODE *temp = queue->front;
		pDataOut = queue->front->pData;
		if (queue->count == 1)
		{
			queue->rear = queue->front = NULL;
		}
		else
		{
			queue->front = queue->front->next;
		}

		free(temp);
		(queue->count)--;
	}

	return pDataOut;
}

void *queueFront(QUEUE *queue)
{
	if (queue->count == 0)
	{
		return NULL;
	}

	return queue->front->pData;
}

void *queueRear(QUEUE *queue)
{
	if (queue->count == 0)
	{
		return NULL;
	}

	return queue->rear->pData;
}

bool emptyQueue(QUEUE *queue)
{
	return (queue->count == 0);
}

bool fullQueue(QUEUE *queue)
{
	QUEUE_NODE *temp = (QUEUE_NODE*)malloc(sizeof(*(queue->rear)));

	if (temp)
	{
		free(temp);
		return false;
	}

	return true;
}

int queueCount(QUEUE *queue)
{
	return queue->count;
}

QUEUE *destroyQueue(QUEUE *queue)
{
	QUEUE_NODE *temp;

	if (queue)
	{
		while(queue->front != NULL)
		{
			free(queue->front->pData);

			temp = queue->front;
			queue->front = queue->front->next;
			free(temp);
		}

		free(queue);
	}

	return NULL;
}
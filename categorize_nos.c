#include "queues.h"

void printQueue(QUEUE *queue)
{
	while(!emptyQueue(queue))
	{
		printf("%d  ", *(int*)queue->front->pData);
		dequeue(queue);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	QUEUE *q0to9 = createQueue();
	QUEUE *q10to19 = createQueue();
	QUEUE *q20to29 = createQueue();
	QUEUE *qOver29 = createQueue();

	bool done = false;

	while(!done)
	{
		printf("Enter a number (EOF to exit): ");

		int *num = (int*)malloc(sizeof(int));

		if (scanf("%d", num) == EOF || fullQueue(q0to9) || fullQueue(q10to19) || fullQueue(q20to29) || fullQueue(qOver29))
		{
			done = true;
			free(num);
		}
		else
		{
			switch(*num / 10)
			{
				case 0: enqueue(q0to9, num);
						break;
				case 1: enqueue(q10to19, num);
						break;
				case 2: enqueue(q20to29, num);
						break;
				default: enqueue(qOver29, num);
						 break;
			}
		}
	}

	printf("\n\nQueue 0 to 9: ");
	printQueue(q0to9);
	printf("\nQueue 10 to 19: ");
	printQueue(q10to19);
	printf("\nQueue 20 to 29: ");
	printQueue(q20to29);
	printf("\nQueue over 29: ");
	printQueue(qOver29);

	destroyQueue(q0to9);
	destroyQueue(q10to19);
	destroyQueue(q20to29);
	destroyQueue(qOver29);

	return 0;
}
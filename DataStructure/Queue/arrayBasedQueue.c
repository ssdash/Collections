#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int capacity;
    int front;
    int rear;
    int *array;
};

struct Queue* createQueue(int capacity)
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(sizeof(queue->capacity*sizeof(int)));
    return queue;
}

int isEmpty(struct Queue* queue)
{
    return queue->size == 0;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

void enqueue(struct Queue* queue,int i)
{
    if(isFull(queue))
    {
	printf("Queue is full\n");
	return;
    }
    if(isEmpty(queue))
    {
	queue->front = queue->rear = 0;
    }
    else
    {
	queue->rear = (queue->rear+1)%(queue->capacity);
    }
    queue->array[queue->rear] = i;
    queue->size = queue->size+1;
}

void dequeue(struct Queue* queue)
{
    if(isEmpty(queue))
    {
	printf("Queue is empty\n");
	return;
    }
    else if(queue->front == queue->rear)
    {
	queue->front = queue->rear = -1;
	queue->size = queue->size-1;
    }
    else
    {
        queue->front = (queue->front+1) % (queue->capacity);
	queue->size = queue->size-1;
    }
}

int front(struct Queue* queue)
{
    if(isEmpty(queue))
	printf("Queue is empty\n");
    return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
    if(isEmpty(queue))
	printf("Queue is empty\n");
    return queue->array[queue->rear];
}

int main()
{
    struct Queue *queue = createQueue(5);
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    dequeue(queue);
    printf("Front element %d\n",front(queue));
    printf("Rear element %d\n",rear(queue));
    printf("Size of the queue %d\n",queue->size);
    return 0;
}

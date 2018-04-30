#include<stdlib.h>
#include<stdio.h>
#include"Queue.h"
typedef struct _queue
{
  int front,rear;
  int *array;
  int capacity;
}queue;

queue* queue_1(int size);
int IsEmpty(queue *q);
int IsFull(queue *q);
void Insert(queue **q,int data);
queue* Delete(queue **q);
int Queue_Size(queue *q);

queue* queue_1(int size)
{
  queue *q=(queue *)malloc(sizeof(queue));
  if(!q)
    return NULL;
  else
    {
      q->front = q->rear = -1;
      q->array = (int *)malloc(sizeof(int)*size);
      q->capacity=size;
    }
  return q; 
}

int IsEmpty(queue *q)
{
  if(q->front==-1)
    return 1;
  else
    return 0;
}

int IsFull(queue *q)
{
  if ( ((q -> rear) + 1) % (q -> capacity)  == (q -> front))
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

void Insert(queue **q,int data)
{
  if(IsFull(*q)==1)
    {
      fprintf(stdout,"Memory Error");
    }
  else
    {
      (*q)->rear=((*q)->rear + 1) % (*q)->capacity;
      (*q)->array[(*q)->rear]=data;
      if( (*q) -> front == -1 )
	{
	  ((*q) -> front ) = ( (*q) -> rear)  ;
	}
    }
} 
queue* Delete(queue **q)
{
  if(IsEmpty(*q)==1)
    {
      fprintf(stdout,"Queue Is already Empty");
      return *q;
    }
 
}

int Queue_Size(queue *q)
{
  if(IsEmpty(q))
    return 0;
  else
    return ((q->rear) - (q->front) + 1);
}



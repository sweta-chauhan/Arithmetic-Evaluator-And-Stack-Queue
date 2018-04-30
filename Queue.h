#ifndef Queue_h_
#define Queue_h_

typedef struct _queue queue;
queue* queue_1(int size);
int IsEmpty(queue *q);
int IsFull(queue *q);
void Insert(queue **q,int data);
queue* Delete(queue **q);
int Queue_Size(queue *q);

#endif

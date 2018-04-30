#ifndef stack_h_
#define stack_h_

typedef struct _stack stack;

stack* stackInit(int size);
void** resizeStack(stack *sp);
int IsEmpty(stack *st);
int IsFull(stack *st);
void Insert(stack **st,void *data);
void Delete(stack **st);
int stack_size(stack *st);

#endif

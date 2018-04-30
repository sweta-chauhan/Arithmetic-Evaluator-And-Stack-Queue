#include<stdlib.h>
#include"stack.h"
#include<stdio.h>
#include<string.h>
typedef struct _stack {
  int capacity;
  int top;
  void** array;
}stack;

stack* stackInit(int size)
{
  stack *st=(stack *)malloc(sizeof(stack));
  if(!st)
    {
      fprintf(stdout,"Memory Error");
    }
  
  else
    {
      if(size<5)
	{
	  size=5;
	}
      st->top=-1;
      st->capacity = size;
      //st->array = (int *)malloc(sizeof(int)*size);
      st->array = malloc(sizeof(void**)*size);
	}
  return st;
 }

int IsEmpty(stack *st)
{
  if(st->top==-1)
    return 1;
  else
    return 0;
}

int IsFull(stack *st)
{
  if(st->top == st->capacity-1)
    return 1;
  else
    return 0;
}
void** resizeStack(stack *sp)
{
  void **tempArray = malloc(sizeof(void**)*sp->capacity*2);
  tempArray=memcpy(tempArray,sp->array,sp->capacity);
  sp->capacity*=2;
  return tempArray;
    
}

void Insert(stack **st,void* data)
{
  if(IsFull(*st))
    {
      printf("Memory Error");
      //return *st;
    }
  else
    {
      (*st)->top = ((*st)-> top +1);
      (*st)->array[(*st)->top]=data;
    }
  
}

void Delete(stack **st)
{
  if(IsEmpty(*st))
    {
      fprintf(stdout,"Stack is Already Empty");
    }
  else
    {
      (*st)->top = (*st)->top -1;
    }
}

int stack_size(stack *st)
{
  if(IsEmpty(st))
    return 0;
  else
    return st->top+1;
}

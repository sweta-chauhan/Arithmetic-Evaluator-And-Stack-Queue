#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void display(stack *sp)
{
  if(!IsEmpty(sp))
    {
      for(int i=0;i<=sp->counter;i++)
	printf("%c",*(char*)sp->container[i]);
    }
}
int isBalancedBracket(char *str)
{
  stack *sp=CreateStack(20);
  int i,flag;
  flag=i=0;
  while(str[i]!='\0')
    {
      
      if(str[i]=='('|| str[i] == '{' || str[i] == '[')
	{
	  push(&sp,&str[i]);
	}
      else
	{
	  if(!IsEmpty(sp))
	    {
	      if(str[i]==')')
		{
		  if(*(char*)top(sp)=='(')
		    {
		      pop(&sp);
		      flag=1;
		    }
		  else
		    return 0;
		}
	      else{
	        if(str[i]=='}')
		{
		  if(*(char*)top(sp)=='{')
		    {
		      pop(&sp);
		    }
		  else
		    return 0;
		}
		else{
		if(str[i]==']')
		{
		  if(*(char*)top(sp)=='[')
		    {pop(&sp); 
		     flag=1;
		    }
		  else
		      return 0;
		}
		}
	      }
	    }  
	}
      i++;
    }
  if(flag==1)
    return 1;
  return 0;
}
  /* if(IsEmpty(sp)==1) */
  /*   return 1; */
  /* freeStack(sp); */
  /* return 0; */



int main(void)
{
  char *str="[{(())}]";
  char *str1="{{{{}}}]]";
  char *str2="((((()))}]";
  char *st3="[(()()())]";
  stack *sp=CreateStack(20);
  //push(&sp,&str);
  //printf("%d",sp->counter);
  //pop(&sp);
  //printf("%d",sp->counter);
  printf("%d",isBalancedBracket(str));
   printf("%d",isBalancedBracket(str1));
     printf("%d",isBalancedBracket(str2));
       printf("%d",isBalancedBracket(st3));
   return 0;
}

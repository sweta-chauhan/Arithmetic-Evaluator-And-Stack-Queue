/*Only Working For Addition,Division,And Multiplication Not For Subtraction*/
/*I know Code is lengthy but Its working so after exam I will improve it and ValidExapression function is working only for without bracket expression validation */
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
int checkOperatorPrecedence(char Op1,char Op2)
{
   if(Op1 == '+' && Op2 == '-')
    return 1;
 if(Op1 == '+' && Op2 == '*')
    return 0;
 if(Op1 == '+' && Op2 == '/')
    return 0;
 if(Op1 == '-' && Op2 == '+')
    return 0;
 if(Op1 == '-' && Op2 == '*')
    return 0;
 if(Op1 == '-' && Op2 == '/')
    return 0;
 if(Op1 == '*' && Op2 == '+')
    return 1;
 if(Op1 == '*' && Op2 == '-')
    return 1;
 if(Op1 == '*' && Op2 == '/')
    return 1;
 if(Op1 == '*' && Op2 == '(')
    return 0;
 
 if(Op1 == '/' && Op2 == '*')
    return 1;
 if(Op1 == '/' && Op2 == '+')
    return 1;
 if(Op1 == '/' && Op2 == '-')
    return 1;
 if(Op1 == '(' && Op2 == '*')
    return 1;
 if(Op1 == '(' && Op2 == '/')
    return 1;
 if(Op1 == '(' && Op2 == '-')
    return 1;
 if(Op1 == '(' && Op2 == '+')
    return 1;
}
double findNum(char *str,int ptr,int *count)
{
  double num;
  double denom;
  stack *sp = CreateStack(20);
  num = 0.0;
  denom = 1.0;
  while((str[ptr]>=48 || str[ptr]==46) && str[ptr]<=58 )
    {
      if(str[ptr]=='.')
	{
	  ptr+=1;
	  denom=1;
	  while(str[ptr]>=48 && str[ptr]<=58)
	    {
	      
	      if(!IsEmpty(sp))
		{
		 
		  denom*=10.0;
		  num = *(double*)pop(&sp);
		  num = num + (double)(str[ptr]-48)/denom;
		  push(&sp,&num);
		
		  ptr++;
		}
	      else
		{
		  denom*=10.0;
		  num =num = num + (double)(str[ptr]-48)/denom;
		  push(&sp,&num);
		  ptr++;
		}
	    }
	}
      else
	{
      if(!IsEmpty(sp))
	{
	  num = *(double*)pop(&sp);
	  num = num *10 +(double)(str[ptr]-48);
	  push(&sp,&num);
	  ptr++;
	}
      else
	{
	  num = num *10 + (double)(str[ptr]-48);
	  push(&sp,&num);
	  ptr++;
	}
      }
  }
  if(!IsEmpty(sp))
	{
	num = *(double*)pop(&sp);
	*count=ptr;
	freeStack(sp);
	return num;
	}
  return num;
}

/*int ValidExpression(char *str)
{
  int i,flag;
  i=flag=0;
  while(str[i]!='\0')
    {
      if(str[i]<48 || str[i]>58)
	{
	  if(str[i]==43||str[i]==42||str[i]==45||str[i]==47||str[i]=='('||str[i]==')')
	    {
	      if(str[i+1]==43||str[i+1]==42||str[i+1]==45||str[i+1]==47)
		{
		  flag = 0;
		  return flag;
		}
	      else
		{
		  flag=1;
		}
	    }
	  else
	    {
	      if(str[i]=='(')
		flag =1;
	      else
		{
	      flag = 0;
	      return flag;
		}
	    }
	}
      else
	flag=1;
      i++;
    }
  if(flag==1)
    {
      if(str[i-1]!=43 && str[i-1]!=42 && str[i-1]!=45 && str[i-1]!=47)
	{return 1;}
      
      return 0;
    }
  return 0;
}*/
double calculate(double num1,double num2,char Op)
{
  double num;
  switch(Op)
    {
    case '+':num = num1+num2;
      break;
    case '-': num=num1-num2;
      break;
    case '*': num = num1*num2;
      break;
    case '/': num = num1/num2;
      break;
    }
  return num;
}
double eval(char *str)
{
  stack *sp=CreateStack(20);
  stack *op=CreateStack(10);
  double *num,num1,num2;
  int k;
  k=0;
  num =(double*)malloc(50*sizeof(int));
  int i,count;
  char Op2,Op1;
  i=count=0;
  num1=num2=0.0;
      while(str[i]!='\0')
	{
	  if(str[i]=='/'||str[i]=='-'||str[i]=='*'||str[i]=='+'||str[i]=='('||str[i]==')')
	    {
	      if(!IsEmpty(op))
		{
		  Op2 = *(char*)top(op);
		  if(checkOperatorPrecedence(str[i],Op2)==1)
		    {
		      if(str[i]=='(')
			{
			  push(&op,&str[i]);
			  i++;
			}
		      else
			{
			  if(str[i]==')')
			    {
			      
			      Op2=*(char*)pop(&op);
			      while(Op2!='(')
				{
				  num1=*(double*)pop(&sp);
				  num2 =*(double*)pop(&sp);
				  num[k]=calculate(num2,num1,Op2);
				  push(&sp,&num[k]);
				  Op2=*(char*)pop(&op);
				  k++;
				}
				
			      i++;
			    } 
			  else
			    {
			      
			      Op1=str[i];
			      i++;
			      num[k] = findNum(str,i,&count);
			      i=count;
			      num1=*(double*)pop(&sp);
			      num[k] = calculate(num1,num[k],Op1);
			      push(&sp,&num[k]);
			      k++;
			    }
			}
		    }
		  else
		    {
		      Op2 = *(char*)top(op);
		      if(Op2 =='(')
			{

			  push(&op,&str[i]);
			  i++;
			}
		      else
			{
			  if(str[i]==')')
			    {

			      Op2=*(char*)pop(&op);
			      while(Op2!='(')
				{
				  num1=*(double*)pop(&sp);
				  num2 =*(double*)pop(&sp);
				  num[k]=calculate(num2,num1,Op2);
				  push(&sp,&num[k]);
				  Op2=*(char*)pop(&op);
				  k++;
				}
				
			      i++;

			    }
			  else
			    {
			      Op2=*(char*)pop(&op);
			      push(&op,&str[i]);
			      i++;
			      num1=*(double*)pop(&sp);
			      num2 =*(double*)pop(&sp);
			      num[k]=calculate(num2,num1,Op2);
			      push(&sp,&num[k]);
			      k++;
			    }
			}
		    }
		}
	      else
		{
		  push(&op,&str[i]);
		  i++;
		}
	    }
	  else
	    {
 	      num[k]=findNum(str,i,&count);
	      i=count;

	      push(&sp,&num[k]);
	      k++;
	    }
	}
 
      while(!IsEmpty(op)) 
       	{  
       	  num1=*(double*)pop(&sp); 
       	  num2=*(double*)pop(&sp); 
       	  Op2=*(char*)pop(&op); 
       	  num[k]=calculate(num2,num1,Op2); 
       	  push(&sp,&num[k]);  
       	  k++;  
       	} 
      
      num1=*(double*)pop(&sp);
      freeStack(sp);
      freeStack(op);
      return num1;
}
int main(void)
{
  char *str="25*2+32";
  char *str3="23*2+32";
  int count;

  printf("%.8f\n",eval("(23*23*45)/((23*23+34)+23)"));
  printf("%.16f\n",eval("(23.34*23.34*45.45)/((23*23+34.344)+23.344)"));
  
  return 0;
}

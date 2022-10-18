
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top=-1;
int size;

void push(char item)
{
    if(top>=size-1)
    {
        printf("STACK OVERFLOW");
        
    }
    else
    {
        top++;
        stack[top]=item;
    }
}

char pop()
{
    char item;
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
    }
    else
    {
        item= stack[top];
        top--;
        return item;
    }
}

int is_operator(char symbol)
{
    if(symbol=='^'||symbol=='/'||symbol=='*'||symbol=='+'||symbol=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if(symbol=='^')
    {
        return 3;
        
    }
    else if(symbol=='/'||symbol=='*')
    {
        return 2;
        
    }
    else if(symbol=='+'||symbol=='-')
    {
        return 1;
        
    }
    else
    {
    return 0;
    }
}

void infixtopostfix(char infix_exp[],char postfix_exp[])
{
    char item,x;
    int i=0,j=0;
    push('(');
    strcat(infix_exp,")");
    item=infix_exp[i];
    
    while(item!= '\0')
    {
        if(item=='(')
        {
            push(item);
        }
        else if(isdigit(item)||isalpha(item))
        {
            postfix_exp[j]=item;
            j++;
        }
        else if(is_operator(item)==1)
        {
            x=pop();
            while(is_operator(x)==1 && precedence(x)>=precedence(item))
            {
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);
            
        }
        else if(item==')')
        {
            x=pop();
            while(x!='(')
            {
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
            
        }
        else
        {
            printf("\n INVALID EXPRESSION");
            
        }
        i++;
        item= infix_exp[i];
    }
    postfix_exp[j]='\0';
}

void main()
{
    char infix[100], postfix[100];
    int open,close,len;
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    printf("Enter the infix expression: \n");
    scanf("%s", infix);
    len = strlen(infix);
    
    for(int i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='(')
            open++;
    }
    for(int i=0;i<strlen(infix);i++)
    {
        if(infix[i]==')')
            close++;
    }
    
    if(is_operator(infix[0])==1||is_operator(infix[len-1])==1)
    {
        printf("INVALID EXPRESSION");
    }
    else 
    {
        if(open==close)
        {
            infixtopostfix(infix,postfix);
            printf("The postfix expression is: \n %s", postfix);
        }
        
        else
        {
                printf("INVALID EXPRESSION");
        }
    }    
    
}



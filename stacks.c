#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 500   //max size of array is 500

double stack[MAX_SIZE];
int top = -1;          //top of empty stack is -1
int validity = 0;      /*this varible helps us identify an invalid expression, if any condition is violated it 
                         adds to itself*/

double Peek();          //Peek() function is used to return the topmost element of stack without poping the it
void Push(double X);    //Push() funtion is used to push an double element in the stacl
double Pop();           //Pop() element is used to pop and return the topmost of stack 
int Is_empty();         //Is_Empty() stack is used to check if the stack is empty
void Print();           /*Print() funtion is used to print every element in stack in order
                          it is not nessesary for evaluating postfix, but is very helpful in debugging*/
void Operate(char Operator); /*Operate() funtion is takes operaror as parameter, pops the stack two times operates the popped values,
                              and then pushes the operated value to the stack*/ 

int main()
{
    char str[3*MAX_SIZE];   //input string
    
    int count = 0;
    scanf("%s", str);
    char *pt;
    pt = strtok (str,",");  //here strtok() funtion is used to split the string by delimiter "," (comma)           
    while (pt != NULL) 
    {
        double a = atof(pt);
        if (a == 0)
        {
            if (*pt == '0')
            {
                Push(a); //Print();
            }
            else
            {
                Operate(*pt); //Print();
            }
        
        }

        else
        {
            Push(a); //Print();
        } 
    
        pt = strtok (NULL, ",");
     
    }
    if((validity == 0) && (top == 0))
    {
        printf("%lf\n", Peek());
    }
    else
    {
        printf("Invalid Expression\n");
    }
    return 0;
}

int Is_empty()
{
    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void Push(double x)
{
    if(top == (MAX_SIZE - 1))
    {
        printf("ERROR: STACK OVERFLOW\n");
        validity+=1;
        return;
    }
    top += 1;
    stack[top] = x;
}

double Pop()
{
    if(Is_empty()!=1)
    {
        printf("ERROR: STACK EMPTY\n");
        validity+=1;
        return 0;
    }
    top -= 1;
    return stack[top+1];
}

double Peek()
{
    if(top == -1)
    {
        printf("ERROR: STACK EMPTY\n");
        validity+=1;
        return 0;
    }
    return stack[top];
}

void Print()
{
    printf("the stack is:");
    for(int i=0; i<=top; i++)
    {
        printf("% lf", stack[i]);
    }
    printf("\n");
}

void Operate(char Operator)
{
    if ((top == 0) || (top == -1))
    {
        validity+=1;
        return;
    }
    
    double n1 = Pop();
    double n2 = Pop();
 
    if (Operator == '+'){
        Push(n2 + n1);
    }
    else if (Operator == '-'){
        Push(n2 - n1);
    }
    else if (Operator == '*'){
        Push(n2 * n1);
    }
    else if (Operator == '/'){
        if (n1 != 0)
        {
            Push(n2 / n1);
        }
        else{
            validity+=1;        //for infinity case
        }
        
    }
    else{
        validity += 1;
    }
}
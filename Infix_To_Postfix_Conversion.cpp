//Infix To Postfix Conversion Using Stack
#include<iostream>
using namespace std;
int precedence(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return 0;
}
void InfixToPostfix(char expr[])
{
    char stack[100],result[100];
    int top=-1,resindex=0,i=0;
    while(expr[i]!='\0')
    {
       char ch=expr[i];
       if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
       {
            result[resindex++]=ch;
       }
       else if(ch=='(')
       {
            stack[++top]=ch;
       }
       else if(ch==')')
       {
            while(top>=0 && stack[top]!='(')
            {
                result[resindex++]=stack[top--];
            }
            if(top>=0)
            {
                top--;
            }
       }
       else
       {
            while(top>=0 && precedence(ch)<=precedence(stack[top]))
            {
                result[resindex++]=stack[top--];
            }
            stack[++top]=ch;
        }
        i++;
    }
    while(top>=0)
    {
        result[resindex++]=stack[top--];
    }
    result[resindex]='\0';
    cout<<"postfix:"<<result<<endl;
}
    
int main()
{
    char expression[]="a+b*d/w-f*g^k";
    InfixToPostfix(expression);
    return 0;
}
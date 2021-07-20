#include <stdio.h>
#include <stdlib.h>
#include"stack.h"


int test_case_is_good(void);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    int n;
    int i;

    scanf("%d", &n);
    clear_keyboard_buffer();
    
    for (i = 0; i < n; i++)
    {
        if (test_case_is_good())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}

int test_case_is_good(void)
{
    char c;
    STACK hStack = stack_init_default();
    Status status;

    int count = 0;


    scanf("%c", &c);
    
    while (c != '\n')
    {
        if (c=='(')
        {
            stack_push(hStack, c);
            
        }
        else if (c == '{')
        {
            stack_push(hStack, c);
          
        }
        else if (c == '[')
        {
            stack_push(hStack, c);
            
            
        }
        else if (c == ')')
        {
            char ch = stack_top(hStack, &status);

            if (ch == '(')
            {

                stack_pop(hStack);
            }
            else
            {
                stack_push(hStack, ch);
            }

        }
        else if (c == '}')
        {
           

            char cha = stack_top(hStack, &status);

            if (cha == '{')
            {

                stack_pop(hStack);
            }
            else
            {
                stack_push(hStack, cha);
            }
        }

        else if (c == ']')
        {
            
            char chap = stack_top(hStack, &status);

            if (chap == '[')
            {

                stack_pop(hStack);
            }
            else
            {
                stack_push(hStack, chap);
            }
           
           
        }
        scanf("%c", &c);
        count++;
        
    }

    
    if (stack_empty(hStack))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    stack_destroy(&hStack);
}

void clear_keyboard_buffer(void)
{
    char c;
    int noc;
    noc = scanf("%c", &c);
    while (noc == 1 && c != '\n')
    {
        scanf("%c", &c);
    }
}




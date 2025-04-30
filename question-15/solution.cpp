#include "stack_sll_header.h"
#include <iostream>
#include <string>
using namespace std;
stackadt::stackadt()
{
    head=NULL;
}

bool is_valid(string);

int main()
{
    int chc;
    do 
    {
        printf("enter: \n\t 1. checking balance\n\t 2. for exit\n");
        printf("enter the choice\n");
        scanf("%d", &chc);
        switch(chc)
        {
            case 1:
            {
                string str;
                cout << "enter a string: ";
                cin >> str; 

                if (is_valid(str))
                    cout << "the string is valid" << endl;
                else
                    cout << "the string is not valid" << endl;

                break;
            }
            case 2:
            {
                return 0;
                break;
            }
            default:
            {
                printf("invalid input");
                break;
            }
        }
    }while(1);
    return 0;
}

bool is_valid(string str) 
{
    stackadt stk;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            stk.push(str[i]);
        }
        else 
        {
            if (stk.empty() || stk.peek() != '(')
                return false;
            stk.pop();
        }
    }
    return stk.empty();
}

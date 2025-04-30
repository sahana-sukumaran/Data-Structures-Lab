//program processes the given string

#include <cstring>
#include "stack_sll_header.h"
using namespace std;
string process(string);
stackadt::stackadt()
{
    head=NULL;
}

int main()
{
    string str;
    printf("enter the string\n");
    cin>>str;
    string ret = process(str);
    cout<<"processed string: "<<ret<<"\n";
}

string process(string str)
{
    stackadt stk;
    for(int i = 0;i<str.length();i++)
    {
        if(str[i]=='+')
        {
            if(stk.empty())
            {
                continue;
            }
            else
            {
                stk.pop();
            }
        }
        else
        {
            int ret=stk.push(str[i]);
        }
    }
    string nstr=" ";
    while(!stk.empty())
    {
        nstr = stk.peek() + nstr;
        stk.pop();
    }
    return nstr;
}


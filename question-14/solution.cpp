//implementation of infix to postfix and its evaluation

#include "stack_sll_header.h"
#include <ctype.h>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

string infix();
string convert(string, stackadt&);
int evaluate(const string&);

stackadt::stackadt()
{
    head = NULL;
}

int main()
{
    int chc;
    stackadt obj;
    string exp;
    while (1)
    {
        printf("enter: \n\t 1. for entering the infix expression \n\t 2. for conversion to postfix \n\t 3. for evaluation of postfix\n\t 4. for exit\n");
        printf("enter your choice \n");
        scanf("%d", &chc);
        cin.ignore();
        switch (chc)
        {
            case 1:
            {
                exp = infix();
                cout << "infix expression: " << exp << "\n";
                break;
            }
            case 2:
            {
                string ret = convert(exp, obj);
                cout << "postfix expression: " << ret << "\n";
                break;
            }
            case 3:
            {
                string postfix = convert(exp, obj); 
                int result = evaluate(postfix);
                cout << "result of postfix evaluation: " << result << "\n";
                obj.pop();
                break;
            }
            case 4:
                exit(0);
            default:
                printf("invalid input\n");
                break;
        }
    }
}

string infix()
{
    string num;
    printf("enter the infix expression \n");
    cin >> num;
    return num;
}

int pre(char let)
{
    if (let == '+' || let == '-')
        return 1;
    else if (let == '*' || let == '/' || let == '%')
        return 2;
    else if(let == '^')
        return 3;
    else
        return -1;
}

string convert(string exp, stackadt& obj)
{
    string post = "";
    for (int i = 0; i < exp.length(); i++)
    {
        if (isdigit(exp[i]))
        {
            post += exp[i];
        }
        else if (exp[i] == '(')
        {
            obj.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!obj.empty() && obj.peek() != '(')
            {
                post += obj.peek();
                obj.pop();
            }
            obj.pop();   
        }
        else
        {
            while (!obj.empty() && (pre(obj.peek()) > pre(exp[i]) || (pre(obj.peek()) == pre(exp[i]) && exp[i] != '^')))
            {
                post += obj.peek();
                obj.pop();
            }

            obj.push(exp[i]);

        }
    }
    while (!obj.empty())
    {
        post += obj.peek();
        obj.pop();
    }
    return post;
}

int evaluate(const string& postfix) {
    stack<long long> st;

    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            st.push(postfix[i] - '0');
        } else {
            long long val2 = st.top(); st.pop();
            long long val1 = st.top(); st.pop();
            switch (postfix[i]) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.top();
}

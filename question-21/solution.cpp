//to implement character binary tree
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>    
#include <stack>
using namespace std;
class treeadt
{
    struct node
    {
        char data;
        struct node* left;
        struct node* right;
    }*head;
    public:
    treeadt()
    {
        head=NULL;
    }
    struct node* gethead()
    {
        return head;
    }
    void sethead(struct node* root)
    {
        head = root;
    }
    void preorder(struct node*);
    void inorder(struct node*);
    void postorder(struct node*);
    void insert(char);
    struct node* exptree(string, struct node*, char);
    int search(struct node*, char, int);
};

int main()
{
    int chc;
    treeadt obj;
    do 
    {
        cout<<("enter: \n\t 1. for inserting\n\t 2. inorder\n\t 3. preorder\n\t 4. postorder\n\t 5. search\n\t 6. construct expression tree\n\t 7. exit\n");
        cout<<("enter the choice\n");
        cin>>chc;
        switch(chc)
        {
            case 1:
            {
                char val;
                cout<<("enter the character to be inserted\n");
                cin>>val;
                int ret;
                stack<char> stk;
                obj.insert(val);
                break;
            }
            case 2:
            {
                obj.inorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 3:
            {
                obj.preorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 4:
            {
                obj.postorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 5:
            {
                char key;
                cout<<"enter the character to be searched \n";
                cin>>key;
                int ret = obj. search(obj.gethead(), key, 0);
                if (ret == 0)
                {
                    cout<<"the character was not found\n";
                }
                else
                {
                    cout<<"the character was found\n";
                }
                break;
            }
            case 6: 
            {
                string post;
                cout<<"enter the postfix expression: ";
                cin>>post;
                obj.sethead(obj.exptree(post, NULL, '\0'));               
                break;
            }
            case 7:
            {
                exit(0);
                break;
            }
            default:
            {
                cout<<"invalid input\n";
            }
        }
    }while(1);
}

void treeadt::insert(char data)
{
    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->data=data;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        queue<struct node*> que;
        que.push(head);
        while(!que.empty())
        {
            struct node* Node = que.front();
            que.pop();
            if (Node->left != nullptr)
            {
                que.push(Node->left);
            }
            else
            {
                Node->left=newnode;
                return;
            }
            if (Node->right != nullptr)
            {
                que.push(Node->right);
            }
            else
            {
                Node->right=newnode;
                return;
            }
        }
    }
}


void treeadt::inorder(struct node* root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}

void treeadt::preorder(struct node* root)
{
    if(root)
    {
        cout<<root->data<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
}

void treeadt::postorder(struct node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"  ";
    }
}

int treeadt::search(struct node* root, char key, int flag)
{
    if (root)
    {
        flag=search(root->left, key, flag);
        if (root->data==key)
        {
            flag++;
        }
        flag=search(root->right, key, flag);
    }
    return flag;
}

treeadt::node* treeadt::exptree(string exp, struct node* root, char data)
{
    int i = 0;
    stack<treeadt::node*> stk;
    while (i < exp.length())
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->right = NULL;
        newnode->left = NULL;
        newnode->data = exp[i];

        if (isalnum(exp[i]))
        {
            stk.push(newnode);
        }
        else
        {
            struct node* o1 = stk.top();
            stk.pop();
            struct node* o2 = stk.top();
            stk.pop();
            newnode->right = o1;
            newnode->left = o2;
            stk.push(newnode);
        }
        i++;
    }
    return stk.top();
}

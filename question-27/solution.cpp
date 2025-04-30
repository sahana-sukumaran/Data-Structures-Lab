#include <iostream>
using namespace std;
void input();

int main()
{
    input();
}

void input()
{
    int test=0;
    cout<<"enter the number of test cases\n";
    cin>>test;
    if(test < 1 || test > 100){
        cout << "invalid number of test cases\n";
        return;
    }
    for (int i=0;i<test;i++)
    {
        int size=0;
        cout<<"enter the number of words\n";
        cin>>size;
        if(size < 1 || size > 1000){
            cout << "invalid number of words\n";
            return;
        }
        string words[3][1000];
        for (int j = 0;j<3;j++)
        {
            for (int k = 0;k<size;k++)
            {
                cout<<"enter player "<<(j+1)<<" word "<<(k+1)<< ": ";
                cin>>words[j][k];
                if(words[j][k].length() != 3){
                    cout << "invalid word length\n";
                    return;
                }
            }
        }
        int py1=0;
        int py2=0;
        int py3=0;
        for(int j=0;j<size;j++)
        {
            string word = words[0][j];
            int flag=0;
            for (int k = 0;k<3;k++)
            {
                for (int l = 0;l<size;l++)
                {
                    if (words[k][l]==word)
                    {
                        flag++;
                    }
                }
            }
            if (flag==1)
            {
                py1+=3;
            }
            else if(flag==2)
            {
                py1+=1;
            }
        }
        for(int j=0;j<size;j++)
        {
            string word = words[1][j];
            int flag=0;
            for (int k = 0;k<3;k++)
            {
                for (int l = 0;l<size;l++)
                {
                    if (words[k][l]==word)
                    {
                        flag++;
                    }
                }
            }
            if (flag==1)
            {
                py2+=3;
            }
            else if(flag==2)
            {
                py2+=1;
            }
        }
        for(int j=0;j<size;j++)
        {
            string word = words[2][j];
            int flag=0;
            for (int k = 0;k<3;k++)
            {
                for (int l = 0;l<size;l++)
                {
                    if (words[k][l]==word)
                    {
                        flag++;
                    }
                }
            }
            if (flag==1)
            {
                py3+=3;
            }
            else if(flag==2)
            {
                py3+=1;
            }
        }
        cout<<py1<<"  "<<py2<<"  "<<py3<<"  "<<"\n";
    }
}

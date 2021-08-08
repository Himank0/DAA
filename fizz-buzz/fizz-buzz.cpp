#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    freopen("output.txt","w",stdout);
    string str="";
    int c3=0;
    int c5=0;
    for(int i=1;i<=100;i++)
    {
        c3++;c5++;
        str = "";
        if(c3==3)
        {
            str += "fizz";
            c3=0;
        }
        if(c5==5)
        {
            str += "Buzz";
            c5=0;
        }
        if(str.empty())
            cout<<i<<endl;
        else
            cout<<str<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
void linearSearch(int arr[],int size,int key)
{
    int flag = 0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key){
            cout<<"present "<<i+1<<endl;
            flag = 1;
        }
    }
    if(flag==0)
        cout<<"not present "<<size<<endl;
    
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        int size,key;
        cin>>size>>key;
        int arr[size];
        for(int i=0;i<size;i++)
            cin>>arr[i];
        linearSearch(arr,size,key);
    }
    return 0;
}
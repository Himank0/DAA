#include<bits/stdc++.h>
using namespace std;
void findPos(int arr[],int size,int key)
{
    int count=0;
    sort(arr,arr+size);
    for (int i = 0; i < size; i++)
    {
        int low=i;
        int high = size-1;
        while (low<high)
        {
        if(arr[high]-arr[low] == key)
        {
            count++;
            low++;high--;
        }
        else if(arr[high]-arr[low] > key)
        {
            high--;
        }
        else
            low++;
        }
   
    } 
    cout<<count<<endl;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int size;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        findPos(arr,size,key);
    }
    return 0;
}
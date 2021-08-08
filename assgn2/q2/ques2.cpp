#include<iostream>
using namespace std;
int findPos(int arr[],int size)
{
    bool found = 0;
    for(int i=size-1;i>=0;i--)
    {
        int low = 0;
        int high = i-1;
        while (low<high)
        {
            if(arr[low]+arr[high]==arr[i])
            {
                cout<<low+1<<", "<<high+1<<", "<<i+1<<endl;
                low++;high--;
                return 1;
            }
            else if(arr[low]+arr[high]>arr[i])
            {
                high--;
            }
            else
                low++;
        }   
    }
    return -1;
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
        if(findPos(arr,size)==-1)
            cout<<"no sequence found"<<endl;
    }
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
void binarySearch(int arr[],int low,int high,int size,int key,int count)
{
    int flag = 0;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid]==key)
        {
            cout<<"present "<<count<<endl;
            flag = 1;
            break;
        }
        else if(arr[mid]<key)
        {
            low = mid + 1; 
        }
        else
        {
            high = mid-1;
        }
    }
    if(!flag)
        cout<<"not present "<<count<<endl;
}
void ExponentialSearch(int arr[],int size,int key)
{
    int low = 0, high = low+1,count=1;
    while(arr[high]<key && high < size)
    {
        low = high + 1;
        high *= 2;
        count++;
    }
    if(arr[high]>=key)
    {
        binarySearch(arr, low, min(high,size-1), size, key,count);
    }
    else
        cout<<"not present "<<count<<endl;
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
        ExponentialSearch(arr,size,key);
    }
    return 0;
}
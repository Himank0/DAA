#include<iostream>
using namespace std;
void BinarySearch(int arr[],int size,int key)
{
    int low = 0;
    int high=size-1;
    int flag = 0;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid]==key)
        {
            cout<<"present "<<mid+1<<endl;
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
        cout<<"not present "<<size;
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
        BinarySearch(arr,size,key);
    }
    return 0;
}
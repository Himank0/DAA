#include<iostream>
#include<cmath>
using namespace std;
int jumpSearch(int arr[],int size,int key,int *count)
{
    int low = 0,high = 0;
    while(arr[high]<key && high<size)
    {
        (*count)++;
        low = high;
        high += sqrt(size);
    }
    high = min(high,size);
    while(arr[low]<key && low<=high)
    {
        (*count)++;
        low++;
        if(arr[low]==key){
            return low;
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
    while (t--)
    {
        int size,key;
        int cnt=0;
        cin>>size>>key;
        int arr[size];
        for(int i=0;i<size;i++)
            cin>>arr[i];
        int ele = jumpSearch(arr,size,key,&cnt);
        if(ele!=-1)
            cout<<"present "<<cnt<<endl;
        else
            cout<<"not present "<<cnt<<endl;
    }
    
    return 0;
}
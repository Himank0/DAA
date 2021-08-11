#include<iostream>
using namespace std;
void swap(int arr[],int a,int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition(int arr[], int low, int high, int &swaps,int &comp)
{
    int piv = arr[high];
    int i=low-1;
    int j = low;
    while(j < high)
    {
        if(arr[j] < piv)
        {
            i++;
            swap(arr,i,j);
            swaps++;
        }
        j++;
        comp++;
    }
    swap(arr,i+1,j);
    swaps++;
    return i+1;
}
void quickSort(int arr[],int low, int high,int &swaps,int &comp)
{
    if(low < high)
    {
        int piv = partition(arr,low,high,swaps,comp);
        quickSort(arr,low,piv-1,swaps,comp);
        quickSort(arr,piv+1,high,swaps,comp);
    }   
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int size,comp=0,swaps=0;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
            cin>>arr[i];
        quickSort(arr,0,size-1,swaps,comp);
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        cout<<"comparisions: "<<comp<<endl;
        cout<<"swaps: "<<swaps<<endl;
    }
    return 0;
}
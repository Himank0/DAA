#include<iostream>
using namespace std;
void InsertionSort(int arr[],int size)
{
    int comparisions = 0;
    int shifts = 0;
    for(int i=1;i<size;i++)
    {
        int key = arr[i];
        int j = i-1;
        while(arr[j]>key && j>=0)
        {
            comparisions++;
            arr[j+1]=arr[j];
            j--;
            shifts++;
        }
        arr[j+1]=key;
        shifts++;
    }
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"comparisions = "<<comparisions<<endl;
    cout<<"shifts = "<<shifts<<endl;
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
        InsertionSort(arr,size);
    }
    return 0;
}
#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high)
{
    int l1 = mid-low+1;
    int l2 = high-mid;
    int arr1[l1],arr2[l2];
    for(int i=0;i<l1;i++)
    {
        arr1[i]=arr[low+i];
    }
    for(int i=0;i<l2;i++)
    {
        arr2[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i<l1 && j<l2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k]=arr1[i];
            i++;k++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;k++;
        }
    }
    while (j<l2)
    {
        arr[k]=arr2[j];
        k++;j++;
    }
    while(i<l1)
    {
        arr[k]=arr1[i];
        k++;i++;
    } 

}
void findDuplicates(int arr[],int size)
{
    bool found = 0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==arr[i+1])
        {
            found=1;
            cout<<"YES"<<endl;
            break;
        }
    }
    if(!found)
        cout<<"NO"<<endl;
}
void MergeSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid = (low + high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
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
        int size;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
            cin>>arr[i];
        MergeSort(arr,0,size-1);
        findDuplicates(arr,size);
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
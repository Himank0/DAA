#include <bits/stdc++.h>
using namespace std;
long long merge(int arr[],int l,int mid,int h,int &comp){
    long long countinv = 0;
    int n1 = mid-l+1;
    int n2 = h-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++)
        a[i] = arr[l+i];
    for(int i=0;i<n2;i++)
        b[i] = arr[mid+1+i];
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(a[i]>b[j]){
            arr[k]=b[j];
            countinv += n1-i;
            k++;j++;
        }
        else{
            arr[k]=a[i];
            k++;i++;   
        }
        comp++;
    }
    while(i<n1){
        arr[k]=a[i];
        k++;i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;j++;
    }
    return countinv;
}
long long mergesort(int arr[],int l,int h,int &comp){
    long long cntinv = 0;
    if(l<h)
    {
        int mid = (l+h)/2;
       cntinv += mergesort(arr,l,mid,comp);
        cntinv += mergesort(arr,mid+1,h,comp);

        cntinv += merge(arr,l,mid,h,comp);
    }
    return cntinv;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int size,comp=0;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
            cin>>arr[i];
        long long cntInv = mergesort(arr,0,size-1,comp);
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        cout<<"comparisions: "<<comp<<endl;
        cout<<"inversions: "<<cntInv<<endl;
    }
    return 0;

}

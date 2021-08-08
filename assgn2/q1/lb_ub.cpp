// lower bound searched value hi dega, agr array me ni h to usee larger value ki position ko return krega
// upper bound searched value se greater value ki position dega
#include<bits\stdc++.h>
using namespace std;
int BinarySearch(int arr[],int size,int key)
{
    int *lb = lower_bound(arr,arr+size,key);
    if(*lb!=key || lb == (arr+size))
        return 0;
    int *ub = upper_bound(arr,arr+size,key);
    return ub - lb;
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
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
            cin>>arr[i];
        cin>>key;
        int ptr = BinarySearch(arr,size,key);
        cout<<key<<"-"<<ptr<<endl;
    }
    return 0;
}

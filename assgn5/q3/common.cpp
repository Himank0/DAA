#include<bits/stdc++.h>
using namespace std;
void findCommon(int arr1[], int m, int arr2[], int n) {
    int i=0,j=0,k=0;
    int ans[m];
    while (i < m  && j < n) {
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if(arr1[i] > arr2[j]) {
            j++;
        }
        else {
            ans[k] = arr1[i];
            i++; j++; k++;
        }
    }
    for (int i=0; i < k; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n;
    cin>>m;
    int* arr1 = new int(m);
    for (int i=0; i<m; i++) {
        cin >> arr1[i];
    }
    cin>>n;
    int* arr2 = new int(n);
    for (int i=0; i<n; i++) {
        cin >> arr2[i];
    }
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);
    findCommon(arr1, m, arr2, n);
    return 0;
}
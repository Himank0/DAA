#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int piv = arr[high];
    int j = low;
    int i = low - 1;
    while (j<high)
    {
        if(arr[j] < piv)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[j]);
    return i+1;
}
int kthSmallestele(int arr[], int low, int high, int k)
{
		int piv = partition(arr, low, high);
		if (piv == k)
			return arr[piv];
		if (piv > k)
			return kthSmallestele(arr, low, piv - 1, k);
        else
		    return kthSmallestele(arr, piv + 1, high,k);
}
int main()
{
	int arr[] = { 10, 4, 5, 8, 6, 11, 26 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	cout << "K-th smallest element is "
		<< kthSmallestele(arr, 0, n - 1, k-1);
	return 0;
}

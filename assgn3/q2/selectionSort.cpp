#include <iostream>
using namespace std;
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selectionSort(int arr[], int size)
{
	int i, j, minIndex,comparision=0,swaps=0;

	for (i = 0; i < size-1; i++)
	{
		minIndex = i;
		for (j = i+1; j < size; j++)
        {
            comparision++;
		    if (arr[j] < arr[minIndex]){
			    minIndex = j;
            }
        }
		swap(&arr[minIndex], &arr[i]);
        swaps++;
	}
    for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
    cout<<"comparisions = "<<comparision<<endl;
    cout<<"swaps = "<<swaps<<endl;
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
        selectionSort(arr,size);
    }
	return 0;
}


#include<iostream>
using namespace std;
void findKeySum(int arr[], int size, int key) {

    int sum;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] < key) {
                if (arr[i] + arr[j] == key ) {
                    cout << arr[i] << " " << arr[j] << endl;
                    return;
                }
            }
            else {
                break;
            }
        }
    }
    cout << "No Such Element Exist" << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int size;
        cin >> size;
        int* arr = new int(size);
        for (int i=0; i < size; i++)
            cin >> arr[i];
        int key;
        cin >> key;
        findKeySum(arr, size, key);
    }    
    return 0;
}
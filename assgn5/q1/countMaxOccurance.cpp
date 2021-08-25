#include<iostream>
using namespace std;
void maxOcc(char ch[], int size) {
    int alpha[26] = {0};
    for(int i = 0; i< size; i++) {
        alpha[ch[i] - 'a']++;
    }
    int maxsize = 0;
    char c;
    for(int i=0; i<26; i++) {
        if(alpha[i] > maxsize) {
            maxsize = alpha[i];
            c = 'a' + i;
        }
    }
    if (maxsize <= 1) {
        cout << "No Duplicates Present" << endl;
        return;
    }
    cout << c << '-' << maxsize << endl;
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
        char* ch = new char(size);
        for (int i=0; i < size; i++)
            cin >> ch[i];
        maxOcc(ch, size);
    }    
    return 0;
}

#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

class PriorityQueue {
	vector<int> pq;
   public:
    PriorityQueue() {
    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size()-1;
        while(childIndex > 0) {
        	int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex]) {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax() {
        if (pq.size() == 0) {
            return INT_MIN;
        }
        return pq[0];
    }

    int removeMax() {
        if (pq.size() == 0) {
            return INT_MIN;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int parentIndex = 0;
        int c1 = 2*parentIndex + 1;
        int c2 = 2*parentIndex + 2;
        int maxIndex = parentIndex;
        while(c1 < pq.size()) {
			if (pq[c1] > pq[maxIndex]) {
                maxIndex = c1;
            }
            if (c2 < pq.size() and pq[c2] > pq[maxIndex]) {
                maxIndex = c2;
            }
            
            if (maxIndex != parentIndex) {
                int temp = pq[maxIndex];
                pq[maxIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }
            
            parentIndex = maxIndex;
            c1 = 2*parentIndex + 1;
            c2 = 2*parentIndex + 2;
        }
        
        return ans;
        
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  
                cout << pq.getMax() << "\n";
                break;
            case 3:  
                cout << pq.removeMax() << "\n";
                break;
            case 4: 
                cout << pq.getSize() << "\n";
                break;
            case 5: 
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        cin >> choice;
    }
}
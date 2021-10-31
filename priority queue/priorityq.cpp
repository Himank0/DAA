// #include<vector>
#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> pq;

    public:
    bool isEmpty() {
        return pq.size() == 0;
        }
    // return the size of priority Queue - no of elements present
    int getSize() {
        return pq.size();
    }
    int getMin() {
        if (isEmpty()) {
            return 0;
        }
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    int removeMin() {
        int ans = getMin();
        int parentIndex = 0;
        int lastIndex = getSize() - 1;

        pq[0] = pq[lastIndex];
        pq.pop_back();
        int child1 = 2*parentIndex + 1;
        int child2 = 2*parentIndex + 2;

        int minIndex = parentIndex;
        while(child2 < lastIndex and child1 < lastIndex) {
            if (pq[child1] < pq[minIndex]) {
                minIndex = child1;
            }
            if (pq[child2] < pq[minIndex]) {
                minIndex = child2;
            }
            
            if (minIndex != parentIndex) {
                int temp = pq[minIndex];
                pq[minIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            parentIndex = minIndex;
            child1 = 2*parentIndex + 1;
            child2 = 2*parentIndex + 2;
        }
        return ans;
    }
    void display()
    {
        cout << "final priority queue is : " << endl;
        for(int i=0; i<getSize(); i++) {
            cout << pq[i] << " ";
        }
        cout << endl;
    } 
};
 
int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            case 6: 
                pq.display();
                break;
            default:
                return 0;
        }
        cin >> choice;
    }
}
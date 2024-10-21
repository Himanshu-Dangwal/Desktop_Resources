#include <bits/stdc++.h>
#define int long long
using namespace std;
#define nl '\n'

class MaxHeap
{
private:
    vector<int> heap;

    void heapify(int index)
    {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
        {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Constructor
    MaxHeap() {}

    // Inserts a value into the max-heap.
    void insert(int value)
    {
        heap.push_back(value);
        int index = heap.size() - 1;
        while (index > 0 && heap[index] > heap[(index - 1) / 2])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Removes and returns the maximum element (root) from the max-heap.
    int extractMax()
    {
        if (heap.empty())
        {
            return -1; // Return a sentinel value to indicate an empty heap.
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return maxValue;
    }

    // Returns the maximum element (root) from the max-heap without removing it.
    int getMax()
    {
        if (heap.empty())
        {
            return -1; // Return a sentinel value to indicate an empty heap.
        }
        return heap[0];
    }

    // Returns the size of the max-heap.
    int size()
    {
        return heap.size();
    }

    // Display
    void display()
    {
        for (auto ele : heap)
        {
            cout << ele << " ";
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> A;
    for (int i = 0; i < n; cin >> A[i++])
        ;

    MaxHeap H = MaxHeap();
    for (int ele : A)
    {
        H.insert(ele);
    }

    H.display();
    cout << endl;

    int m;
    cin >> m;

    vector<int> B;
    for (int i = 0; i < m; cin >> B[i++])
        ;

    for (auto ele : B)
    {
        H.insert(ele);
    }

    H.display();
    return 0;
}
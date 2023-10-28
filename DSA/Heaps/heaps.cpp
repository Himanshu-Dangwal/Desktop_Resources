#include <bits/stdc++.h>
#define int long long
using namespace std;
#define nl '\n'

class MaxHeap
{
private:
    std::vector<int> heap;

    // Helper function to maintain the max-heap property.
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
            std::swap(heap[index], heap[largest]);
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
            std::swap(heap[index], heap[(index - 1) / 2]);
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
};

int findKthLargest(std::vector<int> &nums, int k)
{
    MaxHeap maxHeap;

    for (int num : nums)
    {
        maxHeap.insert(num);
    }

    // Extract the kth largest element.
    for (int i = 1; i < k; i++)
    {
        maxHeap.extractMax();
    }

    return maxHeap.getMax();
}

int main()
{
}
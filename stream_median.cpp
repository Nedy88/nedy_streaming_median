#include "stream_median.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

StreamMedian::StreamMedian(): leftHeap {}, rightHeap {} {}

void StreamMedian::addElement(int elem) {
    /*
     * Keep two heaps (priority queues) for almost equal size.
     * The leftHeap keeps the smallest half of the elements.
     * The rightHeap keeps the greater half of th elements.
     * The leftHeap is maxHeap, the rightHeap is minHeap.
     * The two heaps should be the same size or when odd number
     * of elements, the leftHeap will be one element bigger.
     */
    if (leftHeap.size() == rightHeap.size()) {
        // Add to the left heap. They should be the same size or
        // the left heap should have one element more.
        if (!rightHeap.empty() && elem > rightHeap.top()) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
            rightHeap.push(elem);
        } else {
            leftHeap.push(elem);
        }
    } else if (leftHeap.size() > rightHeap.size()) {
        // Then we have to push to the right heap.
        if (!leftHeap.empty() && elem < leftHeap.top()) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
            leftHeap.push(elem);
        } else {
            rightHeap.push(elem);
        }
    }
}

int StreamMedian::median() {
    /*
     * When we have even number of elements N. The median is the sample with
     * index N/2 in the sorted array.
     */
    if (leftHeap.empty() && rightHeap.empty()) {
        throw out_of_range("Calling median on an empty data structure.");
    }
    if (leftHeap.size() > rightHeap.size()) {
        return leftHeap.top();
    } else {
        return rightHeap.top();
    }
}

DummyMedian::DummyMedian(): data {} {}

void DummyMedian::addElement(int elem) {
    data.push_back(elem);
    sort(data.begin(), data.end());
}

int DummyMedian::median() {
    if (data.empty()) {
        throw out_of_range("Calling median on an empty data structure.");
    }
    return data[data.size() / 2];
}
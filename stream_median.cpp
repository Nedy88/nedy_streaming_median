#include "stream_median.hpp"

#include <algorithm>
#include <vector>

using namespace std;

StreamMedian::StreamMedian(): leftHeap {}, rightHeap {} {}

void StreamMedian::addElement(int elem) {
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
    if (leftHeap.empty() && rightHeap.empty()) {
        // TODO: Handle this better
        return 0;
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
        return 0;
    }
    return data[data.size() / 2];
}
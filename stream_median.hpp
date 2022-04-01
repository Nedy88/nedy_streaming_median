#include <vector>
#include <queue>

using namespace std;

/*
 * Use two heaps of equal size. The left heap is max heap,
 * the right heap is min heap. That makes is easy to add elements
 * and query for the median.
 *
 * Adding element is amortized O(1)
 * Getting the median is O(1) in the worst case.
 */
class StreamMedian {
private:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int> > rightHeap;
public:
    StreamMedian();

    void addElement(int);
    int median();
};

/*
 * Use for testing purposes. Trivial slow implementation.
 */
class DummyMedian {
private:
    vector<int> data;
public:
    DummyMedian();

    void addElement(int);
    int median();
};
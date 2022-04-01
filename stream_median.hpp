#include <vector>
#include <queue>

using namespace std;

class StreamMedian {
private:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int> > rightHeap;
public:
    StreamMedian();

    void addElement(int);
    int median();
};

class DummyMedian {
private:
    vector<int> data;
public:
    DummyMedian();

    void addElement(int);
    int median();
};
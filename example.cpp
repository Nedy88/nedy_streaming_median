#include "stream_median.hpp"

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    StreamMedian obj;
    DummyMedian dummy;
    srand(42);
    vector<int> data(20);
    generate(data.begin(), data.end(), rand);
    for (auto i = 0; i < data.size(); ++i) {
        auto elem = data[i] % 100;
        obj.addElement(elem);
        dummy.addElement(elem);
        cout << obj.median() << " ?= " << dummy.median() << endl;
    }
    return 0;
}
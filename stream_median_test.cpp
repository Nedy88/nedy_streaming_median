#include "stream_median.hpp"

#include <gtest/gtest.h>

#include <algorithm>

using namespace std;

TEST(StreamMedianTest, BasicAssertions) {
    StreamMedian obj;
    DummyMedian dummy;
    srand(42);
    vector<int> testData(20);
    generate(testData.begin(), testData.end(), rand);

    for (auto i = 0; i < testData.size(); ++i) {
        auto elem = testData[i];
        obj.addElement(elem);
        dummy.addElement(elem);
        EXPECT_EQ(obj.median(), dummy.median());
    }
}


TEST(StreamMedianEmptyTest, BasicAssertions) {
    StreamMedian obj;
    EXPECT_EQ(obj.median(), 0);
}
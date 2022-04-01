Data structure to compute median from a stream of data.

To build

    cd build
    cmake ..
    cmake --build .

To run an example program:

    cd build
    ./Example

The example will create a random vector of 20 samples. Will add the 20 samples one by one
and call the median after each addition. It will be done using `StreamMedian` (my solution)
and `DummyMedian` which is dummy solution build for testing purpose. The output will be
the comparison between the two solutions.

To run the tests:

    cd build
    ./StreamMedianTest
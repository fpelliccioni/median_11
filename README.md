# Median of 11

An algorithm for finding the median of 11 elements in a stable way with a maximum of 18 comparisons is presented here.
Although its optimality is not known, there is currently no more efficient algorithm in terms of the number of comparisons.

The algorithm is presented using the following programming languages:

- [C++17](https://github.com/fpelliccioni/median_11/blob/93905bf85f70a657242b957a88e26db23ed966d0/cpp/median_11_stable_18cmps.hpp)
- [Python](https://github.com/fpelliccioni/median_11/blob/9285fb2df0fe69702b26881d4695310ce4b27f50/python/median_11_knuth.py)
- Javascript
- Pseudocode

This algorithm is based on making only 18 comparisons to determine the median, which theoretically makes it more efficient than other algorithms such as QuickSelect. However, despite its theoretical optimization, the algorithm can prove to be much slower than [QuickSelect](https://en.wikipedia.org/wiki/Quickselect) in practice.

The reason for this is the size of the code, which is significantly larger than QuickSelect. The size of the code influences the load on the CPU's [instruction cache](https://en.wikipedia.org/wiki/CPU_cache), which can make the algorithm slower than QuickSelect. In addition, although the algorithm is almost optimal in theory, its implementation in specific programming languages can also affect its performance.

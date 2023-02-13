#define RandomAccessIterator typename
#define ForwardIterator typename
#define BidirectionalIterator typename
#define Compare typename
// #define _LIBCPP_INLINE_VISIBILITY

#include <algorithm>
#include <iterator>

namespace {

// Assumes size > 0
template <Compare Cmp, BidirectionalIterator It>
constexpr
void selection_sort(It first, It last, Cmp comp) {
    using std::swap;
    It lm1 = last;
    for (--lm1; first != lm1; ++first) {
        It i = std::min_element<It, typename std::add_lvalue_reference<Cmp>::type>(first, last, comp);
        if (i != first)
            swap(*first, *i);
    }
}

template <Compare Cmp, ForwardIterator It>
constexpr
unsigned sort3(It x, It y, It z, Cmp c) {
    using std::swap;
    unsigned r = 0;
    if (!c(*y, *x))          // if x <= y
    {
        if (!c(*z, *y))      // if y <= z
            return r;            // x <= y && y <= z
                                   // x <= y && y > z
        swap(*y, *z);          // x <= z && y < z
        r = 1;
        if (c(*y, *x))       // if x > y
        {
            swap(*x, *y);      // x < y && y <= z
            r = 2;
        }
        return r;                // x <= y && y < z
    }
    if (c(*z, *y))           // x > y, if y > z
    {
        swap(*x, *z);          // x < y && y < z
        r = 1;
        return r;
    }
    swap(*x, *y);              // x > y && y <= z
    r = 1;                       // x < y && x <= z
    if (c(*z, *y))           // if y > z
    {
        swap(*y, *z);          // x <= y && y < z
        r = 2;
    }
    return r;
}                                  // x <= y && y <= z

template <Compare Cmp, RandomAccessIterator It>
constexpr
bool nth_element_find_guard(It& i, It& j, It m, Cmp comp) {
    // manually guard downward moving j against i
    while (true) {
        if (i == --j) {
            return false;
        }
        if (comp(*j, *m)) {
            return true;  // found guard for downward moving j, now use unguarded partition
        }
    }
}

template <Compare Cmp, RandomAccessIterator It>
constexpr inline
void nth_element_internal(It first, It nth, It last, Cmp comp) {
    using std::swap;
    // Cmp is known to be a reference type
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    const difference_type limit = 7;
    while (true)
    {
        if (nth == last)
            return;
        difference_type len = last - first;
        switch (len)
        {
        case 0:
        case 1:
            return;
        case 2:
            if (comp(*--last, *first))
                swap(*first, *last);
            return;
        case 3:
            {
            It m = first;
            sort3<Cmp>(first, ++m, --last, comp);
            return;
            }
        }
        if (len <= limit)
        {
            selection_sort<Cmp>(first, last, comp);
            return;
        }
        // len > limit >= 3
        It m = first + len/2;
        It lm1 = last;
        unsigned n_swaps = sort3<Cmp>(first, m, --lm1, comp);
        // *m is median
        // partition [first, m) < *m and *m <= [m, last)
        // (this inhibits tossing elements equivalent to m around unnecessarily)
        It i = first;
        It j = lm1;
        // j points beyond range to be tested, *lm1 is known to be <= *m
        // The search going up is known to be guarded but the search coming down isn't.
        // Prime the downward search with a guard.
        if (!comp(*i, *m))  // if *first == *m
        {
            // *first == *m, *first doesn't go in first part
            if (nth_element_find_guard<Cmp>(i, j, m, comp)) {
                swap(*i, *j);
                ++n_swaps;
            } else {
                // *first == *m, *m <= all other elements
                // Partition instead into [first, i) == *first and *first < [i, last)
                ++i;  // first + 1
                j = last;
                if (!comp(*first, *--j)) {  // we need a guard if *first == *(last-1)
                    while (true) {
                        if (i == j) {
                            return;  // [first, last) all equivalent elements
                        } else if (comp(*first, *i)) {
                            swap(*i, *j);
                            ++n_swaps;
                            ++i;
                            break;
                        }
                        ++i;
                    }
                }
                // [first, i) == *first and *first < [j, last) and j == last - 1
                if (i == j) {
                    return;
                }
                while (true) {
                    while (!comp(*first, *i))
                        ++i;
                    while (comp(*first, *--j))
                        ;
                    if (i >= j)
                        break;
                    swap(*i, *j);
                    ++n_swaps;
                    ++i;
                }
                // [first, i) == *first and *first < [i, last)
                // The first part is sorted,
                if (nth < i) {
                    return;
                }
                // nth_element the second part
                // tao::algorithm::nth_element<Cmp>(i, nth, last, comp);
                first = i;
                continue;
            }
        }
        ++i;
        // j points beyond range to be tested, *lm1 is known to be <= *m
        // if not yet partitioned...
        if (i < j)
        {
            // known that *(i - 1) < *m
            while (true)
            {
                // m still guards upward moving i
                while (comp(*i, *m))
                    ++i;
                // It is now known that a guard exists for downward moving j
                while (!comp(*--j, *m))
                    ;
                if (i >= j)
                    break;
                swap(*i, *j);
                ++n_swaps;
                // It is known that m != j
                // If m just moved, follow it
                if (m == i)
                    m = j;
                ++i;
            }
        }
        // [first, i) < *m and *m <= [i, last)
        if (i != m && comp(*m, *i))
        {
            swap(*i, *m);
            ++n_swaps;
        }
        // [first, i) < *i and *i <= [i+1, last)
        if (nth == i)
            return;
        if (n_swaps == 0)
        {
            // We were given a perfectly partitioned sequence.  Coincidence?
            if (nth < i)
            {
                // Check for [first, i) already sorted
                j = m = first;
                while (true) {
                    if (++j == i) {
                        // [first, i) sorted
                        return;
                    }
                    if (comp(*j, *m)) {
                        // not yet sorted, so sort
                        break;
                    }
                    m = j;
                }
            }
            else
            {
                // Check for [i, last) already sorted
                j = m = i;
                while (true) {
                    if (++j == last) {
                        // [i, last) sorted
                        return;
                    }
                    if (comp(*j, *m)) {
                        // not yet sorted, so sort
                        break;
                    }
                    m = j;
                }
            }
        }
        // nth_element on range containing nth
        if (nth < i)
        {
            // tao::algorithm::nth_element<Cmp>(first, nth, i, comp);
            last = i;
        }
        else
        {
            // tao::algorithm::nth_element<Cmp>(i+1, nth, last, comp);
            first = ++i;
        }
    }
}

template <Compare Cmp>
struct comp_ref_type {
  typedef typename std::add_lvalue_reference<Cmp>::type type;
};

} // anonymous namespace

namespace tao::algorithm {

template <RandomAccessIterator It, Compare Cmp>
inline _LIBCPP_INLINE_VISIBILITY constexpr
void nth_element(It first, It nth, It last, Cmp comp) {
    typedef typename comp_ref_type<Cmp>::type CmpRef;
    nth_element_internal<CmpRef>(first, nth, last, comp);
}

template <RandomAccessIterator It>
inline _LIBCPP_INLINE_VISIBILITY constexpr
void nth_element(It first, It nth, It last) {
    tao::algorithm::nth_element(first, nth, last, std::less<typename std::iterator_traits<It>::value_type>());
}

} // namespace tao::algorithm


#include <array>

template <typename T>
inline constexpr
T median_11(std::array<T, 11> arr) noexcept {
    tao::algorithm::nth_element(arr.begin(), arr.begin() + 5, arr.end());
    return arr[5];
}

inline
bool lt(char a, char b) noexcept {
    return a < b;
}

int main(int argc, char** argv) {

    std::array<char, 11> a = {
        argv[1][0], argv[1][1], argv[1][2], argv[1][3],
        argv[1][4], argv[1][5], argv[1][6], argv[1][7],
        argv[1][8], argv[1][9], argv[1][10]};

    return median_11(a);
}

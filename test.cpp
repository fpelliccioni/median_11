/*
g++ -O3 -std=c++17 -I/home/fernando/dev/tao/algorithm/include test.cpp
*/

// #include "median_11_unstable.hpp"
#include "median_11_stable_18cmps.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <numeric>
// #include <vector>

template <Integer N>
inline constexpr 
N half(N n) { return n >> 1; }

template <Integer N>
inline constexpr 
N factorial(N n) { return std::tgamma(n + 1); }

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& os, std::array<T, N> const& arr) {
    os << '[';
    for (size_t i = 0; i < N - 1; ++i) {
        os << arr[i] << ", ";
    }
    os << arr[N - 1] << ']';
    return os;
}

struct block {
    size_t id;
    size_t time;
};

template <size_t N>
inline
std::array<block, N> create_blocks(std::array<size_t, N> const& times) {
    std::array<block, N> res;
    for (size_t i = 0; i < times.size(); ++i) {
        res[i].id = i;
        res[i].time = times[i];
    }
    return res;
}

// Global variable
size_t g_comparissons = 0;

inline
bool lt(block const& a, block const& b) noexcept {
    ++g_comparissons;
    return a.time < b.time;
}

template <size_t N, size_t max_comps, typename F>
void exec_n_with_permutations(F median_f) {
    size_t total_select_comparissons = 0;
    size_t total_sort_comparissons = 0;
    size_t max_select_comparissons = 0;
    size_t max_sort_comparissons = 0;
    size_t min_select_comparissons = 9999;
    size_t min_sort_comparissons = 9999;

    constexpr auto k = half(N);
    constexpr auto q = factorial(N);

    std::array<size_t, N> element;
    std::iota(std::begin(element), std::end(element), 0);
    // element[1] = element[0];    // Check stability
    // element[2] = element[0];    // Check stability
    // element[3] = element[0];    // Check stability
    // element[4] = element[0];    // Check stability
    // element[5] = element[0];    // Check stability
    // element[6] = element[0];    // Check stability
    // element[7] = element[0];    // Check stability
    // element[8] = element[0];    // Check stability
    // element[9] = element[0];    // Check stability
    // element[10] = element[0];    // Check stability
    std::cout << element << '\n';
    // return;

    size_t i = 0;
    do {
        if (i % 10000 == 0) {
            std::cout << i << " of " << q << "... --- sort cmps: " << total_sort_comparissons << " vs. select cmps: " << total_select_comparissons << " --- " << (double(total_sort_comparissons) / total_select_comparissons) << '\n';
            // std::cout << element << '\n';
        }
        ++i;

        auto blocks = create_blocks(element);

        // std::cout << "Before execute the median algo ${element}` << '\n';
        g_comparissons = 0;
        block m1 = median_f(blocks[0], blocks[1], blocks[2], blocks[3],
                            blocks[4], blocks[5], blocks[6], blocks[7],
                            blocks[8], blocks[9], blocks[10], lt);
        if (g_comparissons > max_comps) {
            std::cout << "ERROR, exceeds the number of comparisons. element: " << element << ". expected <= " << max_comps << ". got: " << g_comparissons << '\n';
            return;
        }        
        total_select_comparissons += g_comparissons;
        if (g_comparissons > max_select_comparissons) {
            max_select_comparissons = g_comparissons;
        }        
        if (g_comparissons < min_select_comparissons) {
            min_select_comparissons = g_comparissons;
        }        

        g_comparissons = 0;
        std::stable_sort(std::begin(blocks), std::end(blocks), lt);
        //TODO: test insertion sort
        total_sort_comparissons += g_comparissons;
        if (g_comparissons > max_sort_comparissons) {
            max_sort_comparissons = g_comparissons;
        }        
        if (g_comparissons < min_sort_comparissons) {
            min_sort_comparissons = g_comparissons;
        }        

        auto expect = blocks[k];

        if (expect.id != m1.id) {
            auto element_sorted = element;
            std::stable_sort(std::begin(element_sorted), std::end(element_sorted), std::less<>{});
            //TODO: test insertion sort
            std::cout << "ERROR " << element << " - " << element_sorted << " - " << expect.id << " - " << m1.id << " - " << expect.time << " - " << m1.time << '\n';
            return;
        }

    } while(std::next_permutation(std::begin(element), std::end(element)));

    std::cout << "i vs q: " << i << " vs " << q << '\n';
    std::cout << "Execution completed OK with     " << i << " elements\n";
    std::cout << "Selection comparissons total:   " << total_select_comparissons << '\n';
    std::cout << "Selection comparissons min:     " << min_select_comparissons << '\n';
    std::cout << "Selection comparissons max:     " << max_select_comparissons << '\n';
    std::cout << "Selection comparissons average: " << (double(total_select_comparissons) / i) << '\n';
    std::cout << "Sort comparissons total:        " << total_sort_comparissons << '\n';
    std::cout << "Sort comparissons min:          " << min_sort_comparissons << '\n';
    std::cout << "Sort comparissons max:          " << max_sort_comparissons << '\n';
    std::cout << "Sort comparissons average:      " << (double(total_sort_comparissons) / i) << '\n';
    std::cout << "Average ratio:                  " << (double(total_sort_comparissons) / total_select_comparissons) << '\n';
}


struct test_select_5_11 {
    template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
        requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Same<J, K> && Domain<R, A>)
    inline constexpr
    auto&& operator()(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) const noexcept {
        return tao::algorithm::select_5_11(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), r);
    }
};

void test_simple(std::array<size_t, 11> const& times) {
    auto blocks = create_blocks(times);
    auto m = tao::algorithm::select_5_11(
        blocks[0], blocks[1], blocks[2], blocks[3],
        blocks[4], blocks[5], blocks[6], blocks[7],
        blocks[8], blocks[9], blocks[10], lt);

    std::cout << "[" << m.id << ", " << m.time << "]" << std::endl;

}

int main() {
    exec_n_with_permutations<11, 19>(test_select_5_11{});

    // test_simple({5, 0, 1, 2, 3, 4, 6, 7, 8, 9, 10});

    // auto m11 = select_5_11(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, std::less<>{});
    // std::cout << m11 << '\n';
    return 0;
}
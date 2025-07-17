#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <algorithm> // For std::swap
#include <iterator>  // For std::distance, std::next, std::prev

// Collection of sorting algorithms for integer arrays
class SortingAlgorithms {
public:
    // Simple O(n²) sorting algorithm
    static void bubbleSort(std::vector<int>& arr);

    // Divide-and-conquer O(n log n) algorithm
    template<typename BidirIt>
    static void mergeSort(BidirIt first, BidirIt last) {
        auto dist = std::distance(first, last);
        if (dist > 1) {
            BidirIt middle = std::next(first, dist / 2);
            mergeSort(first, middle);
            mergeSort(middle, last);
            merge(first, middle, last);
        }
    }

    // Fast O(n log n) average case algorithm
    template<typename ForwardIt>
    static void quickSort(ForwardIt first, ForwardIt last) {
        if (std::distance(first, last) > 1) {
            ForwardIt p = partition(first, last);
            quickSort(first, p);
            quickSort(std::next(p), last);
        }
    }

private:
    // Merge two sorted subarrays
    template<typename BidirIt>
    static void merge(BidirIt first, BidirIt middle, BidirIt last) {
        std::vector<typename std::iterator_traits<BidirIt>::value_type> left(first, middle);
        std::vector<typename std::iterator_traits<BidirIt>::value_type> right(middle, last);
        
        BidirIt it = first;
        auto l_it = left.begin();
        auto r_it = right.begin();

        while (l_it != left.end() && r_it != right.end()) {
            if (*l_it <= *r_it) {
                *it++ = *l_it++;
            } else {
                *it++ = *r_it++;
            }
        }

        while (l_it != left.end()) {
        if (*l_it <= *r_it) {
            *it++ = *l_it++;
        } else {
            *it++ = *r_it++;
        }
    }

    while (l_it != left.end()) {
        *it++ = *l_it++;
    }

    while (r_it != right.end()) {
        *it++ = *r_it++;
    }
}

template<typename BidirIt>
void mergeSort(BidirIt first, BidirIt last) {
    auto dist = std::distance(first, last);
    if (dist > 1) {
        BidirIt middle = std::next(first, dist / 2);
        mergeSort(first, middle);
        mergeSort(middle, last);
        merge(first, middle, last);
    }
}
// Partition helper for quickSort
template<typename ForwardIt>
ForwardIt partition(ForwardIt first, ForwardIt last) {
    auto pivot = *std::prev(last);
    ForwardIt i = first;
    for (ForwardIt j = first; j != std::prev(last); ++j) {
        if (*j < pivot) {
            std::swap(*i++, *j);
        }
    }
    std::swap(*i, *std::prev(last));
    return i;
}

template<typename ForwardIt>
void quickSort(ForwardIt first, ForwardIt last) {
    if (std::distance(first, last) > 1) {
        ForwardIt p = partition(first, last);
        quickSort(first, p);
        quickSort(std::next(p), last);
    }
}

#endif // SORTING_ALGORITHMS_H

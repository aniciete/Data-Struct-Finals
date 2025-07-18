#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <algorithm> // For std::swap
#include <iterator>  // For std::distance, std::next, std::prev

// A utility class that provides a collection of static sorting algorithms.
class SortingAlgorithms {
public:
    /**
     * @brief Sorts a vector of integers using the Bubble Sort algorithm.
     * @param arr The vector of integers to be sorted.
     * @note Time complexity: O(n^2)
     */
    static void bubbleSort(std::vector<int>& arr);

    /**
     * @brief Sorts a range of elements using the Merge Sort algorithm.
     * @tparam BidirIt A bidirectional iterator.
     * @param first An iterator to the beginning of the range.
     * @param last An iterator to the end of the range.
     * @note Time complexity: O(n log n)
     */
    template<typename BidirIt>
    static void mergeSort(BidirIt first, BidirIt last) {
        auto dist = std::distance(first, last);
        if (dist > 1) {
            BidirIt middle = std::next(first, dist / 2);
            mergeSort(first, middle); // Recursively sort the first half.
            mergeSort(middle, last);  // Recursively sort the second half.
            merge(first, middle, last); // Merge the sorted halves.
        }
    }

    /**
     * @brief Sorts a range of elements using the Quick Sort algorithm.
     * @tparam ForwardIt A forward iterator.
     * @param first An iterator to the beginning of the range.
     * @param last An iterator to the end of the range.
     * @note Average time complexity: O(n log n)
     */
    template<typename ForwardIt>
    static void quickSort(ForwardIt first, ForwardIt last) {
        if (std::distance(first, last) > 1) {
            ForwardIt p = partition(first, last); // Partition the array and get the pivot.
            quickSort(first, p); // Recursively sort the left part.
            if (p != last) {
                quickSort(std::next(p), last); // Recursively sort the right part.
            }
        }
    }

private:
    /**
     * @brief Merges two sorted sub-ranges into a single sorted range.
     * @tparam BidirIt A bidirectional iterator.
     * @param first An iterator to the beginning of the first range.
     * @param middle An iterator to the beginning of the second range.
     * @param last An iterator to the end of the second range.
     */
    template<typename BidirIt>
    static void merge(BidirIt first, BidirIt middle, BidirIt last) {
        // Create temporary vectors to hold the left and right halves.
        std::vector<typename std::iterator_traits<BidirIt>::value_type> left(first, middle);
        std::vector<typename std::iterator_traits<BidirIt>::value_type> right(middle, last);
        
        BidirIt it = first;
        auto l_it = left.begin();
        auto r_it = right.begin();

        // Merge the two halves back into the original container.
        while (l_it != left.end() && r_it != right.end()) {
            if (*l_it <= *r_it) {
                *it++ = *l_it++;
            } else {
                *it++ = *r_it++;
            }
        }

        // Copy any remaining elements from the left half.
        while (l_it != left.end()) {
            *it++ = *l_it++;
        }

        // Copy any remaining elements from the right half.
        while (r_it != right.end()) {
            *it++ = *r_it++;
        }
    }

    /**
     * @brief Partitions a range of elements for the Quick Sort algorithm.
     * @tparam ForwardIt A forward iterator.
     * @param first An iterator to the beginning of the range.
     * @param last An iterator to the end of the range.
     * @return An iterator to the pivot element.
     */
    template<typename ForwardIt>
    static ForwardIt partition(ForwardIt first, ForwardIt last) {
        auto pivot = *std::prev(last); // Choose the last element as the pivot.
        ForwardIt i = first;
        // Iterate through the elements and move smaller elements to the left.
        for (ForwardIt j = first; j != std::prev(last); ++j) {
            if (*j < pivot) {
                std::swap(*i++, *j);
            }
        }
        std::swap(*i, *std::prev(last)); // Place the pivot in its correct position.
        return i;
    }
};

#endif // SORTING_ALGORITHMS_H

#include <gtest/gtest.h>
#include <vector>
#include <span>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "RadixSort.h"
#include "RandomQuickSort.h"
#include "CountingSort.h"
#include "ArrGenerator.h"

TEST(BubbleSortTest, UnsortedArr) {
    std::vector<int> arr = {3, 2, 5, 1, 4};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    BubbleSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(BubbleSortTest, SortedArr) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    BubbleSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(BubbleSortTest, IdenticalArr) {
    std::vector<int> arr = {52, 52, 52};
    std::vector<int> expected = {52, 52, 52};

    BubbleSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(BubbleSortTest, RandomArr) {
    auto arr = ArrGenerator::randomArr<int>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    BubbleSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(BubbleSortTestDouble, RandomArr) {
    auto arr = ArrGenerator::randomArr<double
    >(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    BubbleSort<double> sorter;
    sorter.sort(std::span<double>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}



TEST(CountingSortTest, UnsortedArr) {
    std::vector<int> arr = {3, 2, 5, 1, 4};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    CountingSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(CountingSortTest, SortedArr) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    CountingSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(CountingSortTest, IdenticalArr) {
    std::vector<int> arr = {52, 52, 52};
    std::vector<int> expected = {52, 52, 52};

    CountingSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(CountingSortTest, RandomArr) {
    auto arr = ArrGenerator::randomArr<int>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    CountingSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(CountingSortTestDouble, RandomArr) {
    auto arr = ArrGenerator::randomArr<double
    >(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    CountingSort<double> sorter;
    sorter.sort(std::span<double>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}


TEST(InsertionSortTest, UnsortedArr) {
    std::vector<int> arr = {3, 2, 5, 1, 4};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    InsertionSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(InsertionSortTest, SortedArr) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    InsertionSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(InsertionSortTest, IdenticalArr) {
    std::vector<int> arr = {52, 52, 52};
    std::vector<int> expected = {52, 52, 52};

    InsertionSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(InsertionSortTest, RandomArr) {
    auto arr = ArrGenerator::randomArr<int>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    InsertionSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(InsertionSortTestDouble, RandomArr) {
    auto arr = ArrGenerator::randomArr<double
    >(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    InsertionSort<double> sorter;
    sorter.sort(std::span<double>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(SelectionSortTest, UnsortedArr) {
    std::vector<int> arr = {3, 2, 5, 1, 4};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    SelectionSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(SelectionSortTest, SortedArr) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    SelectionSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(SelectionSortTest, IdenticalArr) {
    std::vector<int> arr = {52, 52, 52};
    std::vector<int> expected = {52, 52, 52};

    SelectionSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(SelectionSortTest, RandomArr) {
    auto arr = ArrGenerator::randomArr<int>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    SelectionSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(SelectionSortTestDouble, RandomArr) {
    auto arr = ArrGenerator::randomArr<double>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    SelectionSort<double> sorter;
    sorter.sort(std::span<double>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}


TEST(QuickSortTest, UnsortedArr) {
    std::vector<int> arr = {3, 2, 5, 1, 4};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    QuickSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(QuickSortTest, SortedArr) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    QuickSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(QuickSortTest, IdenticalArr) {
    std::vector<int> arr = {52, 52, 52};
    std::vector<int> expected = {52, 52, 52};

    QuickSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(QuickSortTest, RandomArr) {
    auto arr = ArrGenerator::randomArr<int>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    QuickSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(QuickSortTestDouble, RandomArr) {
    auto arr = ArrGenerator::randomArr<double
    >(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    QuickSort<double> sorter;
    sorter.sort(std::span<double>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, UnsortedArr) {
    std::vector<int> arr = {3, 2, 5, 1, 4};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    MergeSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, SortedArr) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    MergeSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, IdenticalArr) {
    std::vector<int> arr = {52, 52, 52};
    std::vector<int> expected = {52, 52, 52};

    MergeSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, RandomArr) {
    auto arr = ArrGenerator::randomArr<int>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    MergeSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTestDouble, RandomArr) {
    auto arr = ArrGenerator::randomArr<double>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    MergeSort<double> sorter;
    sorter.sort(std::span<double>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}


TEST(RadixSortTest, UnsortedArr) {
    std::vector<int> arr = {3, 2, 5, 1, 4};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    RadixSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(RadixSortTest, SortedArr) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    RadixSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(RadixSortTest, IdenticalArr) {
    std::vector<int> arr = {52, 52, 52};
    std::vector<int> expected = {52, 52, 52};

    RadixSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(RadixSortTest, RandomArr) {
    auto arr = ArrGenerator::randomArr<int>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    RadixSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(RadixSortTestDouble, RandomArr) {
    auto arr = ArrGenerator::randomArr<double>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    RadixSort<double> sorter;
    sorter.sort(std::span<double>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}


TEST(RandomQuickSortTest, UnsortedArr) {
    std::vector<int> arr = {3, 2, 5, 1, 4};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    RandomQuickSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(RandomQuickSortTest, SortedArr) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    RandomQuickSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(RandomQuickSortTest, IdenticalArr) {
    std::vector<int> arr = {52, 52, 52};
    std::vector<int> expected = {52, 52, 52};

    RandomQuickSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(RandomQuickSortTest, RandomArr) {
    auto arr = ArrGenerator::randomArr<int>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    RandomQuickSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

TEST(RandomQuickSortTestDouble, RandomArr) {
    auto arr = ArrGenerator::randomArr<double>(100, -100, 100);
    auto expected = arr;
    std::sort(expected.begin(), expected.end());

    RandomQuickSort<double> sorter;
    sorter.sort(std::span<double>(arr), std::nullopt);

    EXPECT_EQ(arr, expected);
}

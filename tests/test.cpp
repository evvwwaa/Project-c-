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
#include "Visual.h"

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

TEST(ArrGeneratorTest, RandomArrayInt) {
    auto arr = ArrGenerator::randomArr<int>(100, 1, 10);

    EXPECT_EQ(arr.size(), 100);

    for (int val : arr) {
        EXPECT_GE(val, 1);
        EXPECT_LE(val, 10);
    }
}

TEST(ArrGeneratorTest, RandomArrayDouble) {
    auto arr = ArrGenerator::randomArr<double>(50, -5.5, 5.5);

    EXPECT_EQ(arr.size(), 50);

    for (double val : arr) {
        EXPECT_GE(val, -5.5);
        EXPECT_LE(val, 5.5);
    }
}

TEST(ArrGeneratorTest, RandomArrayZeroSize) {
    auto arr = ArrGenerator::randomArr<int>(0, 1, 10);

    EXPECT_TRUE(arr.empty());
}

TEST(ArrGeneratorTest, RandomArraySingleElement) {
    auto arr = ArrGenerator::randomArr<int>(1, 42, 42);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 42);
}




TEST(LoggerTest, SameInstance) {
    Logger& logger1 = Logger::getInstance("test_same.txt");
    Logger& logger2 = Logger::getInstance("test_same.txt");

    EXPECT_EQ(&logger1, &logger2);
}

TEST(LoggerTest, LogLevels) {
    Logger& logger = Logger::getInstance("test_levels.txt");

    EXPECT_NO_THROW(logger.log("Error message", Logger::ERROR));
    EXPECT_NO_THROW(logger.log("Warning message", Logger::WARNING));
    EXPECT_NO_THROW(logger.log("Info message", Logger::INFO));
    EXPECT_NO_THROW(logger.log("Debug message", Logger::DEBUG));
}

TEST(LoggerTest, SetLevel) {
    Logger& logger = Logger::getInstance("test_setlevel.txt");

    EXPECT_NO_THROW(logger.setLevel(Logger::ERROR));
    EXPECT_NO_THROW(logger.setLevel(Logger::WARNING));
    EXPECT_NO_THROW(logger.setLevel(Logger::INFO));
    EXPECT_NO_THROW(logger.setLevel(Logger::DEBUG));
}


TEST(VisualTest, Constructor) {
    EXPECT_NO_THROW(Visual visual);
}

TEST(VisualTest, Title) {
    Visual visual;

    EXPECT_NO_THROW(visual.title("Test Title"));
}

TEST(VisualTest, AlgorithmInfo) {
    Visual visual;

    EXPECT_NO_THROW(visual.algInformation("BubbleSort", "O(n²)"));
}

TEST(VisualTest, EmptyArray) {
    Visual visual;
    std::vector<int> emptyArr;

    EXPECT_NO_THROW(visual.visualize(std::span<int>(emptyArr), -1, -1));
}

TEST(VisualTest, SingleElementArray) {
    Visual visual;
    std::vector<int> singleArr = {42};

    EXPECT_NO_THROW(visual.visualize(std::span<int>(singleArr), 0, 0));
}


TEST(IntegrationTest, CompleteWorkflow) {
    auto arr = ArrGenerator::randomArr<int>(10, 1, 100);
    auto original = arr;

    BubbleSort<int> sorter;
    sorter.sort(std::span<int>(arr), std::nullopt);

    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));

    std::vector<int> sortedOriginal = original;
    std::sort(sortedOriginal.begin(), sortedOriginal.end());
    EXPECT_EQ(arr, sortedOriginal);
}

TEST(IntegrationTest, MultipleSortersSameData) {
    auto arr1 = ArrGenerator::randomArr<int>(20, 1, 50);
    auto arr2 = arr1;
    auto arr3 = arr1;

    BubbleSort<int> bubbleSorter;
    QuickSort<int> quickSorter;
    MergeSort<int> mergeSorter;

    bubbleSorter.sort(std::span<int>(arr1), std::nullopt);
    quickSorter.sort(std::span<int>(arr2), std::nullopt);
    mergeSorter.sort(std::span<int>(arr3), std::nullopt);

    EXPECT_EQ(arr1, arr2);
    EXPECT_EQ(arr2, arr3);
    EXPECT_TRUE(std::is_sorted(arr1.begin(), arr1.end()));
}
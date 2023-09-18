#include <gtest/gtest.h>
#include <iostream>
#include "myarray.h"

TEST(MyArrayTest, CreateContainer) {
    MyArray<int> arr;
    EXPECT_EQ(0, arr.size());
}

TEST(MyArrayTest, PushBack) {
    MyArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    EXPECT_EQ(3, arr.size());
    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
    EXPECT_EQ(3, arr[2]);
}

TEST(MyArrayTest, Insert) {
    MyArray<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.insert(1, 2);
    EXPECT_EQ(3, arr.size());
    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
    EXPECT_EQ(3, arr[2]);
}

TEST(MyArrayTest, EraseFromBack) {
    MyArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.erase(2);
    EXPECT_EQ(2, arr.size());
    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
}

TEST(MyArrayTest, EraseFromFront) {
    MyArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.erase(0);
    EXPECT_EQ(2, arr.size());
    EXPECT_EQ(2, arr[0]);
    EXPECT_EQ(3, arr[1]);
}

TEST(MyArrayTest, EraseFromMiddle) {
    MyArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.erase(1);
    EXPECT_EQ(2, arr.size());
    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(3, arr[1]);
}

TEST(MyArrayTest, GetElement) {
    MyArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    EXPECT_EQ(2, arr[1]);
}

TEST(MyArrayTest, GetSize) {
    MyArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    EXPECT_EQ(3, arr.size());
}

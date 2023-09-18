#include <gtest/gtest.h>
#include "mylist.h"


TEST(MyListTest, CreateList) {
    MyList<int> list;

    ASSERT_EQ(0, list.size());
}

TEST(MyListTest, PushFront) {
    MyList<int> list;

    list.push_front(1);
    list.push_front(2);

    ASSERT_EQ(2, list[0]);
    ASSERT_EQ(1, list[1]);
    ASSERT_EQ(2, list.size());
}

TEST(MyListTest, PushBack) {
    MyList<int> list;

    list.push_back(1);
    list.push_back(2);

    ASSERT_EQ(1, list[0]);
    ASSERT_EQ(2, list[1]);
    ASSERT_EQ(2, list.size());
}

TEST(MyListTest, Insert) {
    MyList<int> list;

    list.push_back(1);
    list.push_back(3);

    list.insert(1, 2);

    ASSERT_EQ(1, list[0]);
    ASSERT_EQ(2, list[1]);
    ASSERT_EQ(3, list[2]);
    ASSERT_EQ(3, list.size());
}

TEST(MyListTest, Erase) {
    MyList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.erase(1);

    ASSERT_EQ(1, list[0]);
    ASSERT_EQ(3, list[1]);
    ASSERT_EQ(2, list.size());
}

TEST(MyListTest, GetElement) {
    MyList<int> list;

    list.push_back(1);
    list.push_back(2);

    int element = list[1];

    ASSERT_EQ(2, element);
}

TEST(MyListTest, GetSize) {
    MyList<int> list;

    list.push_back(1);
    list.push_back(2);

    int size = list.size();

    ASSERT_EQ(2, size);
}


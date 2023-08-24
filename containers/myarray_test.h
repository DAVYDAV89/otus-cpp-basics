#ifndef MYVEC_H
#define MYVEC_H

#include <gtest/gtest.h>
#include <iostream>

template <typename T>
class MyArray
{
    T* arr;
    int capacity;
    int current;

public:
    MyArray()
        : current(0)
        , capacity(1)
    {
        arr = new T[1];
    }

    ~MyArray()
    {
        delete[] arr;
    }

    T &operator[](const int _index)
    {
        return arr[_index];
    }

    void setCapacity()
    {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
    }


    void push_front(const T &_data)
    {
        current++;
        T* temp = new T[current];
        temp[0] = _data;

        for (int i = 1; i < current; i++){
            temp[i] = arr[i-1];
        }
        delete[] arr;
        arr = temp;

        setCapacity();
    }


    void push_back(const T &_data)
    {
        setCapacity();

        arr[current] = _data;
        current++;
    }

    void insert(const int _index, const T &_data)
    {
        current++;
        T* temp = new T[current];

        for (int i = 0; i < current; i++){
            if (i < _index) {
                temp[i] = arr[i];
            }
            if (i == _index) {
                temp[i] = _data;
            }
            if (i > _index) {
                temp[i] = arr[i - 1];
            }
        }
        delete[] arr;
        arr = temp;

        setCapacity();

    }

    void erase (const int _index)
    {
        T* temp = new T[current];
        for (int i = 0; i < current; i++){
            if (i >= _index) {
                temp[i] = arr[i+1];
            }
            else
                temp[i] = arr[i];

        }

        delete[] arr;
        arr = temp;
        current--;
    }

    void show() const
    {
        for (int i = 0; i < current; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }

    int size() const
    {
        return current;
    }
};

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

TEST(MyArrayTest, PushFront) {
    MyArray<int> arr;
    arr.push_front(3);
    arr.push_front(2);
    arr.push_front(1);
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
    arr.erase(arr.size());
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
    arr.erase(arr.size() / 2);
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

#endif // MYVEC_H

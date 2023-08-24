#ifndef MYLIST_H
#define MYLIST_H
#include <gtest/gtest.h>
#include <stdlib.h>
#include <iostream>


template <typename T>
struct Node {
    T data;
    Node* Prev;
    Node* Next;
};

template <typename T>
class MyList
{
    Node<T> *Head;
    Node<T> *Tail;
    int count_el;
public:
    MyList()
        : Head(nullptr)
        , Tail(nullptr)
        , count_el(0)
    {

    };
    ~MyList()
    {
        while (Head)
        {
            Tail = Head->Next;
            delete Head;
            Head = Tail;
            count_el--;
        }
    }

    T &operator[](const int _index)
    {
        int counter = 0;

        Node<T> *current = Head;

        while (current != nullptr)
        {
            if (counter == _index)
            {
                return current->data;
            }
            current = current->Next;
            counter++;
        }
    }

    Node<T>* move(int index)
    {
        Node<T>* t = Head;

        for (int i = 0; i < index; i++)
            t = t->Next;

        return t;
    }

    void push_front(const T &_data)
    {
        Node<T> *elem = new Node<T>;
        if (Head != nullptr) {

            elem->data = _data;
            elem->Prev = nullptr;
            elem->Next = Head;
            Head->Prev = elem;
            Head = elem;
        }
        else {
            elem->Next = nullptr;
            elem->Prev = nullptr;

            elem->data = _data;
            Head = Tail = elem;
        }

        count_el++;
    }


    void push_back(const T &_data)
    {
        Node<T> *elem = new Node<T>;
        if (Head != nullptr) {
            elem->Next = nullptr;
            elem->data = _data;

            elem->Prev = Tail;
            Tail->Next = elem;
            Tail = elem;
        }
        else {
            elem->Next = nullptr;
            elem->Prev = nullptr;

            elem->data = _data;
            Head = Tail = elem;
        }

        count_el++;
    }

    void insert(int _index, const T &_data)
    {
        Node<T> *elem = new Node<T>;

        if (Head == nullptr) {
            elem->Next = nullptr;
            elem->Prev = nullptr;

            elem->data = _data;
            Head = Tail = elem;
        }
        else {
            if (_index == 0) {
                elem->data = _data;
                elem->Prev = nullptr;
                elem->Next = Head;
                Head->Prev = elem;
                Head = elem;
            }
            else {
                if (_index >= count_el) {
                    elem->Next = nullptr;
                    elem->data = _data;

                    elem->Prev = Tail;
                    Tail->Next = elem;
                    Tail = elem;
                }
                else {
                    Node<T> *elemPrev = move(_index - 1);
                    Node<T> *elemCur = move(_index);

                    Node<T> *elemIns = new Node<T>;
                    elemIns->data = _data;

                    elemIns->Next = elemCur;
                    elemIns->Prev = elemPrev;

                    elemPrev->Next = elemIns;
                    elemCur->Prev = elemIns;
                }
            }
        }

        count_el++;
    }


    void erase (int _index)
    {
        if (_index > 0) {
            Node<T> *elemDel = move(_index);

            Node<T> *elemPrev   = move(_index - 1);
            Node<T> *elemNex    = move(_index + 1);

            elemPrev->Next  = elemNex;
            elemNex->Prev   = elemPrev;

            delete elemDel;
            count_el--;
        }
        else {
            Head = nullptr;
            Tail = nullptr;
            count_el = 0;
        }
    }

    void show() const
    {
        Node<T> *temp=Tail;
        temp = Head;

        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->Next;
        }
        std::cout << "\n";
    }

    int size() const
    {
        return count_el;
    }

};

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

#endif // MYLIST_H

#ifndef MYLIST_H
#define MYLIST_H
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

        elem->data = _data;
        elem->Prev = nullptr;
        elem->Next = Head;
        Head->Prev = elem;
        Head = elem;

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

    void erase (int _index)
    {
        Node<T> *elemDel = move(_index - 1);

        Node<T> *elemPrev   = move(_index - 2);
        Node<T> *elemNex    = move(_index);

        elemPrev->Next  = elemNex;
        elemNex->Prev   = elemPrev;

        delete elemDel;
        count_el--;
    }
};

#endif // MYLIST_H

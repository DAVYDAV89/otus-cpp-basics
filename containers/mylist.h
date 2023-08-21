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

    void push_back(T _data)
    {
        Node<T> *temp = new Node<T>;
        temp->Next = nullptr;
        temp->data = _data;
        if (Head != nullptr) {
            temp->Prev = Tail;
            Tail->Next = temp;
            Tail = temp;
        }
        else {
            temp->Prev = nullptr;
            Head = Tail = temp;
        }
        count_el++;
    }

    void insert(int _index, T _data)
    {
        Node<T> *temp = new Node<T>;
        temp->Next = nullptr;
        temp->data = _data;
        if (Head == nullptr) {
            temp->Prev = nullptr;
            Head = Tail = temp;
        }
        else {
            if (_index == 0) {
                Node<T> *temp = new Node<T>;
                temp->data = _data;
                temp->Prev = nullptr;
                temp->Next = Head;
                Head->Prev = temp;
                Head = temp;
            }
            else {
                Node<T> *elemPrev = move(_index - 1);
                Node<T> *elemCur = move(_index);
            }
        }

        count_el++;
    }

    void show()
    {
        Node<T> *temp=Tail;
        temp = Head;

        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->Next;
        }
        std::cout << "\n";
    }

    int size()
    {
        return count_el;
    }

    void erase (int _index)
    {
//        Node<T> *el = Move(_index);

        count_el--;
    }

//    void &operator[] ()
//    {

//    }


};

#endif // MYLIST_H

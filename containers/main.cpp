#include "mylist.h"
#include "myarray.h"

using namespace std;


template <typename T>
void do_it( T &_el)
{
    for (int i = 0; i < 10; i++ )
        _el.push_back(i);
    _el.show();
    cout << "size: " << _el.size() << endl;

    _el.erase(2);
    _el.erase(3);
    _el.erase(4);
    _el.show();

    _el.push_front(10);
    _el.show();

    _el.insert(_el.size() / 2, 20);
    _el.show();

    _el.push_back(30);
    _el.show();
}


int main()
{
    MyList<int> lst;
    cout << "-----------MyList-------------" << endl;
    do_it(lst);

    MyArray<int> arr;
    cout << "-----------MyArray-------------" << endl;
    do_it(arr);


    return 0;
}

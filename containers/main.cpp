#include "mylist.h"

using namespace std;

int main()
{
    MyList<int> lst;
    for (int i = 0; i < 10; i++ )
        lst.push_back(i);
    lst.show();
    cout << "size: " << lst.size() << endl;

    lst.erase(3);
    lst.erase(4);
    lst.erase(5);
    lst.show();

    lst.push_front(10);
    lst.show();

    lst.insert(lst.size() / 2, 20);
    lst.show();

    lst.push_back(30);
    lst.show();

    return 0;
}

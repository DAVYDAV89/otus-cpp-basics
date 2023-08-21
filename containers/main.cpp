#include "mylist.h"

using namespace std;

int main()
{
    MyList<int> lst;
    for (int i = 0; i < 10; i++ )
        lst.push_back(i);

    lst.show();

    cout << lst.size() << endl;

    lst.insert(0, 34);

    lst.show();


    return 0;
}

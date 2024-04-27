#include <iostream>
using namespace std;
#include "./List/List.h"

int main()
{
    List list;
    const int size = 10;
    int arr[size] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < size; ++i) {
        list.addToHead(arr[i]);
    }
    list.show();

    list.addToHead(0);
    list.show();

    list.addToTail(77);
    list.show();

    list.deleteFromHead();
    list.show();

    list.deleteFromTail();
    list.show();

    list.insertIntoPosition(88, 5);
    list.show();

    list.deleteIntoPosition(3);
    list.show();

    cout << list.getSearchEl(10) << endl;

    list.addToTail(6);
    list.show();

    cout << list.changeEL(6, 0) << endl;
    list.show();

    list.reverse();
    list.show();



    return 0;
}
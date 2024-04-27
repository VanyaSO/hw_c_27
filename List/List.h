#ifndef HW_C_27_LIST_H
#define HW_C_27_LIST_H
#include "../Node/Node.h"

//Завдання №1
//Створіть шаблонний клас однозв’язного списку для
//        роботи з цілими значеннями. Потрібно створити реалізації для типових операцій над елементами:
//■ AddToHead — додавання елемента до голови списку;
//■ AddToTail — додавання елемента до хвоста списку;
//■ DeleteFromHead — видалення елемента з голови списку;
//■ DeleteFromTail — видалення елемента з хвоста списку;
//■ DeleteAll — видалення всіх елементів;
//■ Show — виведення всіх елементів списку на екран


class List {
    Node* _head;
    Node* _tail;
    unsigned int _size;
    void reverseRecursion(Node*, Node*);
public:
    List();
    List(const List& list);
    ~List();
    void addToHead(int);
    void addToTail(int);
    void deleteFromHead();
    void deleteFromTail();
    void deleteAll();
    void insertIntoPosition(int, int);
    void deleteIntoPosition(int);
    int getSearchEl(int) const;
    int changeEL(int, int);
    void reverse();
    void show() const;

};


#endif

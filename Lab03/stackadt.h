#include <iostream>
#include <cstdlib>
#include <QString>

#ifndef STACK
#define STACK

class Stack
{
public:
    typedef QString Item;



    static const int CAPACITY = 42;

    Stack() { used = 0; }

    void push(Item entry);
    Item pop();
    Item getRandom();


    size_t size() { return used; }


    bool empty() { return used == 0; }

private:

    Item data[CAPACITY];
    int used;



};

#endif



#include <iostream>
#include <cstdlib>

#include "stackadt.h"

void Stack::push(Item entry)
{
    data[used++] = entry;
}

Stack::Item Stack::pop()
{
    return data[--used];
}

Stack::Item Stack::getRandom()
{
    int selection = rand() % used+1;
    Stack temp;
    while (used > selection) {
            temp.push(data[--used]);
        }
    QString target = data[--used];
    while (temp.size() > 0) {
        data[used++]=temp.pop();
    }

    return target;
}


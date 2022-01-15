#ifndef CREADFILE_H
#define CREADFILE_H
#include <functional>
#include <QDebug>
#include <QTextStream>
#include <QFile>

#include "stackadt.h"

class CReadFile
{
private:
    std::vector<std::reference_wrapper< Stack>> m_stacks{};
public:
    CReadFile();
    void add(Stack&);
    Stack getEven();
    Stack getOdd();
    void replaceEven(Stack stack);
    void replaceOdd(Stack stack);
    int readInput();
};

#endif

#ifndef CRANDOM_H
#define CRANDOM_H
#include <QDebug>

#include "stackadt.h"
#include "creadfile.h"


class CRandom
{

private:
    Stack& m_stackOdd ;
    Stack& m_stackEven ;

public:

    CRandom(Stack& stackO, Stack& stackE)
        :m_stackOdd{ stackO }, m_stackEven {stackE}
    {

    }
    QString GetRandomTitle(int);
    QString GetOddTitle();
    QString GetEvenTitle();
    Stack& GetOdd();
    Stack& GetEven();
    size_t size();


    void test(QString);
};


#endif


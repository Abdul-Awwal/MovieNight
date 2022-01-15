#include "crandom.h"


QString CRandom::GetRandomTitle(int)
{

}

QString CRandom::GetOddTitle()
{
    Stack temp;
    QString title;
    if (!m_stackOdd.empty()){
        int selection = rand() % m_stackOdd.size()+1;
        qDebug() <<"Selection: "<<selection <<"Odd size" << m_stackOdd.size();
        while (m_stackOdd.size() > selection) {
             temp.push(m_stackOdd.pop());
        }
        while(temp.size() > 0)
            m_stackOdd.push(temp.pop());
        title = m_stackOdd.pop();
    }
    else if (!m_stackEven.empty())
        return GetEvenTitle();
    else
        title = "No More Movies";
    qDebug() << "TITLE in GETODD: " <<title;
    return title;
}

QString CRandom::GetEvenTitle()
{
    Stack temp;
    QString title;
    qDebug() <<"In CRandom::GetEvenTitle   m_stackEven.size: "<<m_stackEven.size();
    if (!m_stackEven.empty()){
        qDebug() << "in stackEven not empty ";
        int selection = rand() % m_stackEven.size()+1;
        while (m_stackEven.size() > selection) {
             temp.push(m_stackEven.pop());
        }
        title = m_stackEven.pop();
        qDebug() <<"In if  title: "<<title;
        while(temp.size() > 0)
            m_stackEven.push(temp.pop());

    }
    else if (!m_stackOdd.empty()){
        qDebug() << "in stackOdd not empty ";
        return GetOddTitle();
    }
    else
        title = "No More Movies";

    qDebug() <<"Title before return title in GetEvenTitle: " <<title;
    return title;
}

Stack& CRandom:: GetOdd()
{
    return m_stackOdd;
}

Stack &CRandom::GetEven()
{
    return m_stackEven;
}

size_t CRandom::size()
{
    return m_stackEven.size()+m_stackOdd.size();
}

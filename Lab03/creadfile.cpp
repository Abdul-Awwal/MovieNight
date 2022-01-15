#include "creadfile.h"


CReadFile::CReadFile()
{

}

void CReadFile::add(Stack & stack)
{
    m_stacks.push_back(stack);
}

Stack CReadFile::getEven()
{
    return m_stacks.back();
}

Stack CReadFile::getOdd()
{
    return m_stacks.front();
}

void CReadFile::replaceEven(Stack stack)
{
    m_stacks[1]=stack;
}

void CReadFile::replaceOdd(Stack stack)
{
    Stack temp2, temp3;
    for (auto& stack : m_stacks) {
        //temp2 = m_stacks.front();
        while(!stack.get().empty()){
             QString test = stack.get().pop();
             temp2.push(test);
             qDebug()<<"Before replace loop: "<<test;
        }
    }
    m_stacks.push_back(temp2);


    Stack temp = m_stacks.back();
    m_stacks.pop_back(); m_stacks.pop_back();
    m_stacks.push_back(stack);
    m_stacks.push_back(temp);

    qDebug() << "replaced stack";
    for (auto& stack : m_stacks) {
        //temp2 = m_stacks.front();
        while(!stack.get().empty()){
             QString test = stack.get().pop();
             temp3.push(test);
             qDebug()<<"After replace loop: "<<test;
        }
    }
     m_stacks.push_back(temp3);
}


int CReadFile::readInput()
{
    int count = 0;

    QFile inputfile("C:/Users/ibuku/Documents/Lab03/movie_list.txt");

    if(!inputfile.exists())
    {
        qCritical() << "File not found";
    }
    if(!inputfile.open(QIODevice::ReadOnly))
    {
        qCritical() << "Could not open file";
        qCritical() <<inputfile.errorString();
    }


    QTextStream infile(&inputfile);
    //qDebug() <<"About to read";
    while (!infile.atEnd()) {
        QString line;
        char ch;

        for (auto& stack : m_stacks) {
            infile >> ch; infile >> ch;
            if (count >= 9) {
                infile >> ch;
            }
            line = infile.readLine();
           // qDebug() << line;
            stack.get().push(line);
            count++;
        }
    }
    return count;
}

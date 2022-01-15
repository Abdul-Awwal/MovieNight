#include "cfantasymovies.h"
#include <QDebug>



CFantasyMovies::CFantasyMovies(const QString &movieTitle, const QString &userRandomNumber, const Stack &stackOdd, const Stack &stackEven, const CRandom &CRandom) : m_movieTitle(movieTitle),
    m_userRandomNumber(userRandomNumber),
    m_stackOdd(stackOdd),
    m_stackEven(stackEven),
    m_CRandom(CRandom)
{}
CFantasyMovies::CFantasyMovies(QObject *parent) : QObject(parent) , m_movieTitle("The movie to watch is:"), m_userRandomNumber("")
{

}


void CFantasyMovies::anotherFunction()
{
    qDebug() <<"Another function";
}

QString CFantasyMovies::getMovieTitle()
{
    ++classCounter;
    qDebug() <<"IN getMovieTitle" <<m_movieTitle <<classCounter;
    QString s = QString::number(classCounter);
    return m_movieTitle;
}

QString CFantasyMovies::movieTitle()
{
    return m_movieTitle;
}


void CFantasyMovies::setMovieTitle(QString parity)
{

    if (parity == "2")
    {

        m_movieTitle = m_CRandom.GetEvenTitle();

    }
    else if(parity == "odd"){

        m_movieTitle = m_CRandom.GetOddTitle();

    }
    else
        m_movieTitle = "End of the world";
    qDebug() << "m_movieTitle before emit" << m_movieTitle;

}

QString CFantasyMovies::getUserRandomNumber()
{

    qDebug() << "m_userRandom in getUserRandom: " << m_userRandomNumber;

    return m_userRandomNumber;
}

void CFantasyMovies::callMe()
{
    qDebug() << "Success";
}

QString CFantasyMovies::userRandomNumber()
{
    return m_userRandomNumber;
}

size_t CFantasyMovies::size()
{
    return m_stackEven.size() + m_stackOdd.size();
}

void CFantasyMovies::setUserRandomNumber(QString newNum)
{

    m_userRandomNumber = newNum;
    QString selection {};
    if (m_userRandomNumber.toInt() % 2 == 0) {
        selection = "2";
    }
    else
        selection = "odd";
    qDebug() <<"Selection is: "<< selection;

    setMovieTitle(selection);
    emit userRandomNumberChanged(QVariant(m_movieTitle));
    emit movieTitleChanged(m_movieTitle);
}

#include "QBertObserver.h"

QBertObserver::QBertObserver()
    :Observer<QBertComponent>(), m_IsNotified{false}, m_Score{0},m_Event{QBertComponent::Event::endStage}
{
}

void QBertObserver::onNotify(const QBertComponent& data)
{
    switch (data.GetCurrentEvent())
    {
    case QBertComponent::Event::coughtSlickOrSam:
        m_Score += 300;
        break;
    case QBertComponent::Event::defeatedCoily:
        m_Score += 500;
        break;
    case QBertComponent::Event::endStage:
        m_Score += 50;
        break;
    case QBertComponent::Event::tileColorChange:
        m_Score += 25;
        break;
    }

    m_IsNotified = true;
}

bool QBertObserver::IsNotified()
{
    return m_IsNotified;
}

void QBertObserver::SetIsNotified(bool isNotified)
{
    m_IsNotified = isNotified;
}

QBertComponent::Event QBertObserver::GetEvent()
{
    return m_Event;
}

size_t QBertObserver::GetScore()
{
    return m_Score;
}

#include "QBertPCH.h"
#include "CoilyComponent.h"
#include <random>
#include "GameTime.h"

CoilyComponent::CoilyComponent(std::weak_ptr<Hidden::SpriteComponent> eggSprite, std::weak_ptr<Hidden::SpriteComponent> coilySprite, std::weak_ptr<MovementComponent> movementComponent, int pyramidSize)
    :Component(), 
    m_EggSpriteComponent{eggSprite}, 
    m_CoilySpriteComponent{coilySprite}, 
    m_MovementComponent{movementComponent},
    m_QbertMovementObserver{std::make_shared<MovementObserver>()},
    m_CurrentState{State::sitting},
    m_IsEgg{ true },
    m_CurrentRotation{Rotation::backLeft},
    m_PyramidSize{pyramidSize},
    m_QbertPositions{},
    m_DeltaTime{ 0 },
    m_MoveDelay{2.0f},
    m_NrTrackesPositions{3}
{
}

void CoilyComponent::Update()
{

    if (m_IsEgg)
    {
        if (m_DeltaTime < m_MoveDelay)
        {
            m_DeltaTime += GameTime::GetTime();
            return;
        }
        m_DeltaTime = 0;

        int randomNumber = rand() % 2;


        auto shrdMove = m_MovementComponent.lock();

        if (shrdMove->GetRow() == m_PyramidSize - 1)
        {
            m_CurrentState = State::moving;
            m_IsEgg = false;
            ProcessSprite();
        }
        else
        {
            if (randomNumber == 0)
            {
                shrdMove->MoveDownLeft();
            }
            else
            {
                shrdMove->MoveDownRight();
            }
        }
        return;
    }

    if (m_QbertMovementObserver->IsNotified())
    {
        if (m_QbertPositions.size() > m_NrTrackesPositions)
        {
            m_QbertPositions.pop();
        }

       m_QbertPositions.push(std::pair<int,int>( m_QbertMovementObserver->GetRow(),m_QbertMovementObserver->GetColumn()));

        m_QbertMovementObserver->SetIsNotified(false);
    }





    if (m_CurrentState == State::moving)
    {
        if (m_DeltaTime < m_MoveDelay)
        {
            m_DeltaTime += GameTime::GetTime();
            ProcessSprite();
            return;
        }
        m_CurrentState = State::sitting;
        m_DeltaTime = 0;
    }
    else if(m_CurrentState == State::sitting)
    {

        if (m_DeltaTime < m_MoveDelay)
        {
            m_DeltaTime += GameTime::GetTime();
            ProcessSprite();
            return;
        }

        auto shrdMove = m_MovementComponent.lock();
        std::pair<int, int> m_QbertPos{};
        if (m_QbertPositions.size() > 0)
        {
             m_QbertPos = m_QbertPositions.front();
            m_QbertPositions.pop();
        }
        int rowOffset = shrdMove->GetRow() - m_QbertPos.first;
        int colOffset = shrdMove->GetColumn() - m_QbertPos.second;
        if (rowOffset >= 0 && colOffset > 0)
        {
            shrdMove->MoveUpLeft();
            m_CurrentState = State::moving;
        }
        else if (rowOffset >= 0 && colOffset <= 0)
        {
            shrdMove->MoveUpRight();
            m_CurrentState = State::moving;
        }
        else if (rowOffset <= 0 && colOffset >= 0)
        {
            shrdMove->MoveDownLeft();
            m_CurrentState = State::moving;
        }
        else if (rowOffset <= 0 && colOffset < 0)
        {
            shrdMove->MoveDownRight();
            m_CurrentState = State::moving;
        }
    }
    ProcessSprite();
}

std::weak_ptr<Hidden::Subject<CoilyComponent>> CoilyComponent::GetSubject()
{
    return m_pSubject;
}

std::shared_ptr<MovementObserver> CoilyComponent::GetMovementObserver()
{
    return m_QbertMovementObserver;
}

void CoilyComponent::SetQbertIntialPos(const std::pair<int, int> qbertPos)
{
    m_QbertPositions.push(qbertPos);
}

void CoilyComponent::ProcessSprite()
{

    if (m_IsEgg)
    {
        auto spriteComponent = m_EggSpriteComponent.lock();

        spriteComponent->SetCol(static_cast<int>(m_CurrentState));

        return;
    }
    
    auto spriteComponent = m_CoilySpriteComponent.lock();

    spriteComponent->SetCol((static_cast<int>(m_CurrentRotation) * 2) + static_cast<int>(m_CurrentState));

}

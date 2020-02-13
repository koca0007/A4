#include "Mars.h"

namespace GameDev2D
{
    Mars::Mars(double duration)
    {
        m_Elapsed = 0.0;
        m_MarsDuration = duration;
        m_IsRunning = false;
        m_DoesLoop = false;
    }

    Mars::Mars(const Mars& aMars)
    {
        m_Elapsed = aMars.m_Elapsed;
        m_MarsDuration = aMars.m_MarsDuration;
        m_IsRunning = aMars.m_IsRunning;
        m_DoesLoop = aMars.m_DoesLoop;
    }

    Mars::Mars()
    {
        m_Elapsed = 0.0;
        m_MarsDuration = 0.0;
        m_IsRunning = false;
        m_DoesLoop = false;
    }

    void Mars::Update(double delta)
    {
        if (m_IsRunning == true)
        {
            m_Elapsed += delta;

            if (m_Elapsed >= m_MarsDuration)
            {
                if (m_DoesLoop == true)
                {
                    m_Elapsed = 0.0;
                }
                else
                {
                    m_IsRunning = false;
                    m_Elapsed = m_MarsDuration;
                }
            }
        }
    }

    void Mars::Start()
    {
        m_IsRunning = true;
    }

    void Mars::Stop()
    {
        m_IsRunning = false;
    }

    void Mars::Reset()
    {
        m_Elapsed = 0.0;
        m_IsRunning = false;
    }

    void Mars::SetDuration(double aDuration)
    {
        m_MarsDuration = aDuration;
    }

    void Mars::SetDoesLoop(bool aDoesLoop)
    {
        m_DoesLoop = aDoesLoop;
    }

    float Mars::GetMarsPercentage()
    {
        return (float)(m_Elapsed / m_MarsDuration);
    }

    double Mars::GetElapsed()
    {
        return m_Elapsed;
    }

    double Mars::GetDuration()
    {
        return m_MarsDuration;
    }

    bool Mars::IsRunning()
    {
        return m_IsRunning;
    }

    bool Mars::DoesLoop()
    {
        return m_DoesLoop;
    }
}
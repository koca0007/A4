#include "Venus.h"

namespace GameDev2D
{
    Venus::Venus(double duration)
    {
        m_Elapsed = 0.0;
        m_VenusDuration = duration;
        m_IsRunning = false;
        m_DoesLoop = false;
    }

    Venus::Venus(const Venus& aVenus)
    {
        m_Elapsed = aVenus.m_Elapsed;
        m_VenusDuration = aVenus.m_VenusDuration;
        m_IsRunning = aVenus.m_IsRunning;
        m_DoesLoop = aVenus.m_DoesLoop;
    }

    Venus::Venus()
    {
        m_Elapsed = 0.0;
        m_VenusDuration = 0.0;
        m_IsRunning = false;
        m_DoesLoop = false;
    }

    void Venus::Update(double delta)
    {
        if (m_IsRunning == true)
        {
            m_Elapsed += delta;

            if (m_Elapsed >= m_VenusDuration)
            {
                if (m_DoesLoop == true)
                {
                    m_Elapsed = 0.0;
                }
                else
                {
                    m_IsRunning = false;
                    m_Elapsed = m_VenusDuration;
                }
            }
        }
    }

    void Venus::Start()
    {
        m_IsRunning = true;
    }

    void Venus::Stop()
    {
        m_IsRunning = false;
    }

    void Venus::Reset()
    {
        m_Elapsed = 0.0;
        m_IsRunning = false;
    }

    void Venus::SetDuration(double aDuration)
    {
        m_VenusDuration = aDuration;
    }

    void Venus::SetDoesLoop(bool aDoesLoop)
    {
        m_DoesLoop = aDoesLoop;
    }

    float Venus::GetVenusPercentage()
    {
        return (float)(m_Elapsed / m_VenusDuration);
    }

    double Venus::GetElapsed()
    {
        return m_Elapsed;
    }

    double Venus::GetDuration()
    {
        return m_VenusDuration;
    }

    bool Venus::IsRunning()
    {
        return m_IsRunning;
    }

    bool Venus::DoesLoop()
    {
        return m_DoesLoop;
    }
}
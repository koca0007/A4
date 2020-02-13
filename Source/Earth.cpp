#include "Earth.h"

namespace GameDev2D
{
    Earth::Earth(double duration)
    {
        m_Elapsed = 0.0;
        m_EarthDuration = duration;
        m_IsRunning = false;
        m_DoesLoop = false;
    }

    Earth::Earth(const Earth& aEarth)
    {
        m_Elapsed = aEarth.m_Elapsed;
        m_EarthDuration = aEarth.m_EarthDuration;
        m_IsRunning = aEarth.m_IsRunning;
        m_DoesLoop = aEarth.m_DoesLoop;
    }

    Earth::Earth()
    {
        m_Elapsed = 0.0;
        m_EarthDuration = 0.0;
        m_IsRunning = false;
        m_DoesLoop = false;
    }

    void Earth::Update(double delta)
    {
        if (m_IsRunning == true)
        {
            m_Elapsed += delta;

            if (m_Elapsed >= m_EarthDuration)
            {
                if (m_DoesLoop == true)
                {
                    m_Elapsed = 0.0;
                }
                else
                {
                    m_IsRunning = false;
                    m_Elapsed = m_EarthDuration;
                }
            }
        }
    }

    void Earth::Start()
    {
        m_IsRunning = true;
    }

    void Earth::Stop()
    {
        m_IsRunning = false;
    }

    void Earth::Reset()
    {
        m_Elapsed = 0.0;
        m_IsRunning = false;
    }

    void Earth::SetDuration(double aDuration)
    {
        m_EarthDuration = aDuration;
    }

    void Earth::SetDoesLoop(bool aDoesLoop)
    {
        m_DoesLoop = aDoesLoop;
    }

    float Earth::GetEarthPercentage()
    {
        return (float)(m_Elapsed / m_EarthDuration);
    }

    double Earth::GetElapsed()
    {
        return m_Elapsed;
    }

    double Earth::GetDuration()
    {
        return m_EarthDuration;
    }

    bool Earth::IsRunning()
    {
        return m_IsRunning;
    }

    bool Earth::DoesLoop()
    {
        return m_DoesLoop;
    }
}
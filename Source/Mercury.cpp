#include "Mercury.h"

namespace GameDev2D
{
    Mercury::Mercury(double duration)
    {
        m_Elapsed = 0.0;
        m_MercuryDuration = duration;
        m_IsRunning = false;
        m_DoesLoop = false;
    }

    Mercury::Mercury(const Mercury& aMercury)
    {
        m_Elapsed = aMercury.m_Elapsed;
        m_MercuryDuration = aMercury.m_MercuryDuration;
        m_IsRunning = aMercury.m_IsRunning;
        m_DoesLoop = aMercury.m_DoesLoop;
    }

    Mercury::Mercury()
    {
        m_Elapsed = 0.0;
        m_MercuryDuration = 0.0;
        m_IsRunning = false;
        m_DoesLoop = false;
    }

    void Mercury::Update(double delta)
    {
        if (m_IsRunning == true)
        {
            m_Elapsed += delta;

            if (m_Elapsed >= m_MercuryDuration)
            {
                if (m_DoesLoop == true)
                {
                    m_Elapsed = 0.0;
                }
                else
                {
                    m_IsRunning = false;
                    m_Elapsed = m_MercuryDuration;
                }
            }
        }
    }

    void Mercury::Start()
    {
        m_IsRunning = true;
    }

    void Mercury::Stop()
    {
        m_IsRunning = false;
    }

    void Mercury::Reset()
    {
        m_Elapsed = 0.0;
        m_IsRunning = false;
    }

    void Mercury::SetDuration(double aDuration)
    {
        m_MercuryDuration = aDuration;
    }

    void Mercury::SetDoesLoop(bool aDoesLoop)
    {
        m_DoesLoop = aDoesLoop;
    }

    float Mercury::GetMercuryPercentage()
    {
        return (float)(m_Elapsed / m_MercuryDuration);
    }

    double Mercury::GetElapsed()
    {
        return m_Elapsed;
    }

    double Mercury::GetDuration()
    {
        return m_MercuryDuration;
    }

    bool Mercury::IsRunning()
    {
        return m_IsRunning;
    }

    bool Mercury::DoesLoop()
    {
        return m_DoesLoop;
    }
}
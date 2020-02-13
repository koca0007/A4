#pragma once

#include "Constants.h"

namespace GameDev2D
{
	class Mercury
	{
	public:
		Mercury(double duration);
		Mercury(const Mercury& timer);
		Mercury();

		void Update(double delta);

		void Start();
		void Stop();
		void Reset();

		void SetDuration(double duration);
		void SetDoesLoop(bool doesLoop);

		float GetMercuryPercentage();

		double GetElapsed();
		double GetDuration();
		bool IsRunning();
		bool DoesLoop();

	private:
		double m_MercuryDuration;
		double m_Elapsed;
		bool m_IsRunning;
		bool m_DoesLoop;
	};
}

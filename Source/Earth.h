#pragma once

#include "Constants.h"

namespace GameDev2D
{
	class Earth
	{
	public:
		Earth(double duration);
		Earth(const Earth& timer);
		Earth();

		void Update(double delta);

		void Start();
		void Stop();
		void Reset();

		void SetDuration(double duration);
		void SetDoesLoop(bool doesLoop);

		float GetEarthPercentage();

		double GetElapsed();
		double GetDuration();
		bool IsRunning();
		bool DoesLoop();

	private:
		double m_EarthDuration;
		double m_Elapsed;
		bool m_IsRunning;
		bool m_DoesLoop;
	};
}

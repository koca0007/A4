
#pragma once

#include "Constants.h"

namespace GameDev2D
{
	class Mars
	{
	public:
		Mars(double duration);
		Mars(const Mars& timer);
		Mars();

		void Update(double delta);

		void Start();
		void Stop();
		void Reset();

		void SetDuration(double duration);
		void SetDoesLoop(bool doesLoop);

		float GetMarsPercentage();

		double GetElapsed();
		double GetDuration();
		bool IsRunning();
		bool DoesLoop();

	private:
		double m_MarsDuration;
		double m_Elapsed;
		bool m_IsRunning;
		bool m_DoesLoop;
	};
}

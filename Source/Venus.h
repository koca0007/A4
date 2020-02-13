
#pragma once

#include "Constants.h"

namespace GameDev2D
{
	class Venus
	{
	public:
		Venus(double duration);
		Venus(const Venus& timer);
		Venus();

		void Update(double delta);

		void Start();
		void Stop();
		void Reset();

		void SetDuration(double duration);
		void SetDoesLoop(bool doesLoop);

		float GetVenusPercentage();

		double GetElapsed();
		double GetDuration();
		bool IsRunning();
		bool DoesLoop();

	private:
		double m_VenusDuration;
		double m_Elapsed;
		bool m_IsRunning;
		bool m_DoesLoop;
	};
}

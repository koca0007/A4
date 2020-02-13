#pragma once

#include <GameDev2D.h>
#include "Timer.h"
#include "Earth.h"
#include "Mercury.h"
#include "Mars.h"
#include "Venus.h"


namespace GameDev2D
{
	//Class definition
	class Game
	{
	public:
		Game();  //Constructor
		~Game(); //Destructor

		//Write game logic in the Update method
		void Update(double delta);

		//Render game objects in the Draw method
		void Draw();

		//Input methods
		void HandleLeftMouseClick(float mouseX, float mouseY);
		void HandleRightMouseClick(float mouseX, float mouseY);
		void HandleMouseMove(float mouseX, float mouseY, float previousX, float previousY);
		void HandleKeyPress(Keyboard::Key key);
		void HandleKeyReleased(Keyboard::Key key);
		
	private:
		//Member variables GO HERE 
        SpriteAtlas* m_Earth;
        SpriteAtlas* m_Mars;
        SpriteAtlas* m_Space;
        SpriteAtlas* m_Mercury;
        SpriteAtlas* m_Sun;
        SpriteAtlas* m_Venus;

        Polygon* m_EarthOrbit;
		Polygon* m_MarsOrbit;
		Polygon* m_MercuryOrbit;
		Polygon* m_VenusOrbit;

		// the scale is: 1 AU = 220 px
        Timer m_Timer;
		Earth m_EarthTimer;
		Mercury m_MercuryTimer;
		Mars m_MarsTimer;
		Venus m_VenusTimer;
	};
}

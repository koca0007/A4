#include "Game.h"
#include "Constants.h"



// the scale is: 1 AU = 220 px
namespace GameDev2D
{
	Game::Game()
	{
        m_VenusTimer.SetDuration(VENUS_DURATION);
        m_VenusTimer.SetDoesLoop(true);
        m_VenusTimer.Start();

        m_EarthTimer.SetDuration(EARTH_DURATION);
        m_EarthTimer.SetDoesLoop(true);
        m_EarthTimer.Start();

        m_MercuryTimer.SetDuration(MERCURY_DURATION);
        m_MercuryTimer.SetDoesLoop(true);
        m_MercuryTimer.Start();

        m_MarsTimer.SetDuration(MARS_DURATION);
        m_MarsTimer.SetDoesLoop(true);
        m_MarsTimer.Start();

        LoadTexture("Assets");

        m_Space = new SpriteAtlas("Assets");
        m_Space->UseFrame("Background");
        m_Space->SetScale(Vector2(2.0f, 2.0f));

        // 220 pixels away from the Sun
        m_Earth = new SpriteAtlas("Assets");
        m_Earth->UseFrame("Earth");
        m_Earth->SetAnchor(Vector2(0.5f, 0.5f));
        m_Earth->SetPosition(Vector2(GetScreenWidth() / 2.0f - EARTH_SCALE, 300.0f));
        m_EarthOrbit = new Polygon();
        m_EarthOrbit->MakeCircle(EARTH_SCALE, false);
        m_EarthOrbit->SetPosition(Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
        m_EarthOrbit->SetAnchor(0.5f, 0.5f);
        
        //330 pixels away from the Sun
        m_Mars = new SpriteAtlas("Assets");
        m_Mars->UseFrame("Mars");
        m_Mars->SetAnchor(Vector2(0.5f, 0.5f));
        m_Mars->SetPosition(Vector2(GetScreenWidth() / 2.0f - MARS_SCALE, GetScreenHeight() / 2.0f));
        m_MarsOrbit = new Polygon();
        m_MarsOrbit->MakeCircle(MARS_SCALE, false);
        m_MarsOrbit->SetAnchor(0.5f, 0.5f);
        m_MarsOrbit->SetPosition(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);

        //88 pixels away from the Sun
        m_Mercury = new SpriteAtlas("Assets");
        m_Mercury->UseFrame("Mercury");
        m_Mercury->SetAnchor(Vector2(0.5f, 0.5f));
        m_Mercury->SetPosition(Vector2(GetScreenWidth() / 2.0f - MERCURY_SCALE, GetScreenHeight() / 2.0f) );
        m_MercuryOrbit = new Polygon();
        m_MercuryOrbit->MakeCircle(MERCURY_SCALE, false);
        m_MercuryOrbit->SetAnchor(0.5f, 0.5f);
        m_MercuryOrbit->SetPosition(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);

        m_Sun = new SpriteAtlas("Assets");
        m_Sun->UseFrame("Sun");
        m_Sun->SetAnchor(Vector2(0.5f, 0.5f));
        m_Sun->SetPosition(Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));

        //158 pixels away from the Sun
        m_Venus = new SpriteAtlas("Assets");
        m_Venus->UseFrame("Venus");
        m_Venus->SetAnchor(Vector2(0.5f, 0.5f));
        m_Venus->SetPosition(Vector2(GetScreenWidth() / 2.0f - VENUS_SCALE, GetScreenHeight() / 2.0f));
        m_VenusOrbit = new Polygon();
        m_VenusOrbit->MakeCircle(VENUS_SCALE, false);
        m_VenusOrbit->SetAnchor(0.5f, 0.5f);
        m_VenusOrbit->SetPosition(Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
	}

	Game::~Game()
	{
        SafeDelete(m_Earth);
        UnloadTexture("Earth");

        SafeDelete(m_Mars);
        UnloadTexture("Mars");

        SafeDelete(m_Space);
        UnloadTexture("Background");

        SafeDelete(m_Mercury);
        UnloadTexture("Mercury");

        SafeDelete(m_Sun);
        UnloadTexture("Sun");

        SafeDelete(m_Venus);
        UnloadTexture("Venus");
	}

	void Game::Update(double delta)
	{
        m_VenusTimer.Update(delta);
        m_EarthTimer.Update(delta);
        m_MercuryTimer.Update(delta);
        m_MarsTimer.Update(delta);

      
       float earthRadians = m_EarthTimer.GetEarthPercentage() * (M_PI * 2);
       float marsRadians = m_MarsTimer.GetMarsPercentage() * (M_PI * 2);
       float mercuryRadians = m_MercuryTimer.GetMercuryPercentage() * (M_PI * 2);
       float venusRadians = m_VenusTimer.GetVenusPercentage() * (M_PI * 2);
       
       // the scale is: 1 AU = 220 px
       m_Earth->SetPosition(Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f) + Vector2(cos(earthRadians), sin(earthRadians)) * EARTH_SCALE);
       m_Mars->SetPosition(Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f) + Vector2(cos(marsRadians), sin(marsRadians)) * MARS_SCALE);
       m_Mercury->SetPosition(Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f) + Vector2(cos(mercuryRadians), sin(mercuryRadians)) * MERCURY_SCALE);
       m_Venus->SetPosition(Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f) + Vector2(cos(venusRadians), sin(venusRadians)) * VENUS_SCALE);
        

        
        
	}

	void Game::Draw()
	{
        
        m_Space->Draw();
        m_Sun->Draw();
        m_Venus->Draw();
        m_Earth->Draw();
        m_Mars->Draw();
        m_Mercury->Draw();
        m_EarthOrbit->Draw();
        m_MarsOrbit->Draw();
        m_MercuryOrbit->Draw();
        m_VenusOrbit->Draw();
	}

	void Game::HandleLeftMouseClick(float aMouseX, float aMouseY)
	{

	}

	void Game::HandleRightMouseClick(float aMouseX, float aMouseY)
	{

	}

	void Game::HandleMouseMove(float aMouseX, float aMouseY, float aPreviousX, float aPreviousY)
	{
		
	}

	void Game::HandleKeyPress(Keyboard::Key aKey)
	{

	}

	void Game::HandleKeyReleased(Keyboard::Key key)
	{

	}
}
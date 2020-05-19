/*!
\file game.cpp
*/
#include "game.h"

Game::Game()
{
	m_view.setCenter(0.f, 0.f);
	m_view.setSize(m_worldSize);

	m_pWorld = new b2World(mk_gravity);

	m_debugDraw.setWorld(m_pWorld);

	// Simple box to keep the ball in bounds
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.f, 3.f), sf::Vector2f(200.f, 0.1f), 0.f, sf::Color::Green));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.f, -3.f), sf::Vector2f(200.f, 0.1f), 0.f, sf::Color::Green));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-100.f, 0.f), sf::Vector2f(1.f, 6.f), 0.f, sf::Color::Green));


	//setting up the ball
	m_ballDirection = 0.0f;
	m_ball = new DynamicCircle(m_pWorld, sf::Vector2f(-96, -2.f), 0.08f, m_ballDirection, sf::Color::Blue);

	//Finish line sensor
	m_finish = FinishLineSensor(m_pWorld, sf::Vector2f(100.f, 0.0f), sf::Vector2f(1.f, 6.f), 0.f);
	m_finish.setUserData(&m_finish);
	
	//Enemy platform sensors
	m_enemySensors.push_back(EnemySensor(m_pWorld, sf::Vector2f(-50.f, 2.f), sf::Vector2f(1.f, 1.f), 0.f, m_ball));
	//m_enemySensors.setUserData(&m_enemySensors);

	//for (EnemySensor enemy : m_enemySensors) enemy.setUserData(&enemy);
	for (int i = 0; i < m_enemySensors.size(); ++i)
	{
		m_enemySensors[i].setUserData(&m_enemySensors[i]);
	}
	m_pWorld->SetContactListener(&m_listener);
}

Game::~Game()
{
	// Clean up all pointers
	delete m_pWorld;
	m_pWorld = nullptr;
}

void Game::update(float timestep)
{
	// Update the world
	m_pWorld->Step(timestep, mk_iVelIterations, mk_iVelIterations);

	// Update each dyanmic element - effectively update render information
	m_ball->update();
	


	const sf::Vector2f posi = m_ball->getPosition();
	if (posi.x >= -96.5 && posi.x <= 96.5)
	m_view.setCenter(posi.x, 0);



	// Delete debug shapes
	if (m_debug) m_debugDraw.clear();
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Set the view
	target.setView(m_view);


	for (StaticBlock block : m_staticBlocks) target.draw(block);

	target.draw(*m_ball);

	target.draw(m_finish);

	for (EnemySensor enemy : m_enemySensors) target.draw(enemy);

	// Debug Draw
	if (m_debug) target.draw(m_debugDraw);
}

void Game::processKeyPress(sf::Keyboard::Key code)
{
	switch (code)
	{
	case sf::Keyboard::Tab:
		toggleDebug();
		break;
	case sf::Keyboard::Space:
		m_ball->applyImpulse(b2Vec2(0.00f, 0.1f));
		break;
	case sf::Keyboard::Right:
		m_ball->applyVelocity(b2Vec2(15.00f, 0.00f));
		break;
	case sf::Keyboard::Left:
		m_ball->applyVelocity(b2Vec2(-5.00f, 0.00f));
		break;

	}
}



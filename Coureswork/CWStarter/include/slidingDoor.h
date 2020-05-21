#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "physicalThing.h"

class SlidingDoor : public sf::Drawable, public PhysicalThing
{
private:
	b2Body* m_leftSide;
	b2Body* m_leftDoor;
	b2Body* m_rightSide;
	b2Body* m_rightDoor;
	b2MotorJoint* m_leftMotor;
	b2MotorJoint* m_rightMotor;

	sf::RectangleShape m_side1;
	sf::RectangleShape m_side2;
	sf::RectangleShape m_door1;
	sf::RectangleShape m_door2;

	sf::Texture m_sideTex;
	sf::Texture m_doorTex;

	enum { CLOSED, OPENING, OPEN, CLOSING } m_state;
	float m_fElapsedTime;
	float m_fMotionTime;
public:
	SlidingDoor() {}; //!< Default constructor
	SlidingDoor(b2World* world, sf::Vector2f position, float angle);
	void update(float timestep);
	void open();
	void close();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
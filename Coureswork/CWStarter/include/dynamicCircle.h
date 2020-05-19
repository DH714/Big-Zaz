#pragma once

/*!
\file dynamicCircle.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalObject.h"

/*! \class DynamicCircle
\brief A simple circle which can move, rotate and collide with stuff
*/

class DynamicCircle : public sf::CircleShape, public PhysicalObject
{
private:
	bool m_stopped = false;

	enum {RESPAWNING, RESPAWNED, WAITING} m_respawn;
	
public:
	DynamicCircle() {}; //!< Default constructor
	DynamicCircle(b2World * world, sf::Vector2f& position, float radius, float orientation, sf::Color colour); //!< Complete contructor
	void update(); //!< Update rendering infomation 
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< Overridden drawing methos to include line to allow users to see oreintation of the ball
	void applyImpulse(b2Vec2 impulse); //!< Apply impulse to the body
	void applyVelocity(b2Vec2 velocity);
	void accel(b2Vec2 acc);//!< Apply force to the body
	bool isStopped() const; //!< Has the circle stopped moving
	void respawn();
};

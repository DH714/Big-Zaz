#pragma once

#include <SFML/Graphics.hpp>

#include "physicalObject.h"

class RotatingDoor : public PhysicalObject, public sf::Drawable
{
private:
	sf::RectangleShape m_rectangle;
	b2Body* m_anchor;
	b2RevoluteJoint* m_hinge;
public:
	RotatingDoor() {}; //!< Default constructor
	RotatingDoor(b2World* world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation, sf::Color colour); // Full constructor
	RotatingDoor(b2World* world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation, sf::Texture* tex); // Full constructor
	void draw(sf::RenderTarget& render, sf::RenderStates states) const; //!< Draw door
	void update();
};

#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "physicalObject.h"

class FinalDoor : public sf::RectangleShape, public PhysicalObject
{
private:

public:

	FinalDoor(b2World* world, sf::Vector2f position, sf::Vector2f size, float orientation, sf::Color colour); //!< Complete contructor
	void open();
	bool m_open = false;
};
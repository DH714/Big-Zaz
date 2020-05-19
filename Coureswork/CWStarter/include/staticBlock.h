#pragma once

/*!
\file staticBlock.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalObject.h"

/*! \class StaticBlock
\brief A simple block which can not move or rotate but can collide with stuff
*/

class StaticBlock : public sf::RectangleShape, public PhysicalObject
{
public:
	StaticBlock(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, sf::Color colour); //!< Complete contructor
};
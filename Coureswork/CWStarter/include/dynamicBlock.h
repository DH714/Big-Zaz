#pragma once
/*!
\file dynamicBlock.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalObject.h"

/*! class dynamicBlock
\ brief A simple block object in the world
*/

class DynamicBlock : public sf::RectangleShape, public PhysicalObject
{
public:
	DynamicBlock(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation); //!< Complete contructor
	void update(); //!< Update rendering infomation 
};
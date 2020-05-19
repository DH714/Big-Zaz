#pragma once
/*!
\file finishLineSensor.cpp
*/
#include "finishLineSensor.h"
FinishLineSensor::FinishLineSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation)
{
	initRectangle(world, position, size, orientation);
	setFillColor(sf::Color::Yellow);
}

void FinishLineSensor::onAction(b2Body * other)
{
	exit(1);
}
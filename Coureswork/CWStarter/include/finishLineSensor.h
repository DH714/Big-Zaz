#pragma once
/*!
\file finishLineSensor.h
*/

#include "staticSensor.h"
class FinishLineSensor : public StaticSensor
{
private:

public:
	FinishLineSensor() {}; //!< Default constructor
	FinishLineSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation);
	void onAction(b2Body * other);
	void offAction(b2Body * other) {};

};
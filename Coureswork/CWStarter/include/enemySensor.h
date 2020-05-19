#pragma once
/*!
\file enemySensor.h
*/

#include "staticSensor.h"
#include "dynamicCircle.h"



class EnemySensor : public StaticSensor
{
private:

public:
	EnemySensor() {}; //!< Default constructor
	EnemySensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, DynamicCircle * ball);
	void onAction(b2Body * other);
	void offAction(b2Body * other) {};
	DynamicCircle * m_ball;

};
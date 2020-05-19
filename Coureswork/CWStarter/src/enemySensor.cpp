#pragma once

#include "enemySensor.h"


EnemySensor::EnemySensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, DynamicCircle * ball)
{
		initRectangle(world, position, size, orientation);
		m_ball = ball;
		setFillColor(sf::Color::Red);
}

void EnemySensor::onAction(b2Body * other)
{
	m_ball->respawn();

}

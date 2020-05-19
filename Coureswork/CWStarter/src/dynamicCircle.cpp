/*!
\file dynamicCircle.cpp
*/

#include "dynamicCircle.h"


DynamicCircle::DynamicCircle(b2World * world, sf::Vector2f& position, float radius, float orientation, sf::Color colour)
{
	b2BodyDef l_bodyDef;
	b2CircleShape l_shape;
	b2FixtureDef l_fixtureDef;

	m_respawn = RESPAWNED;


	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	m_body = world->CreateBody(&l_bodyDef);
	m_body->SetUserData(this); // used by our contact listener

	l_shape.m_radius = radius;

	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fRestitution;
	l_fixtureDef.shape = &l_shape;

	m_body->CreateFixture(&l_fixtureDef);
	m_body->SetLinearDamping(0.2f);
	m_body->SetAngularDamping(0.2f);

	setPosition(position);
	setRadius(radius);
	setOrigin(radius, radius);
	setRotation(orientation);
	setFillColor(colour);
}

void DynamicCircle::update()
{
	// Check whether the circle has stopped (simualated ground friction)
	m_stopped = m_body->GetLinearVelocity().Length() < 0.1f;
	//If stopped trim any remaining velocity
	if (m_stopped)
	{
		m_body->SetLinearVelocity(b2Vec2(0.f, 0.f));
		m_body->SetAngularVelocity(0.0f);
	}

	//b2Vec2 pos = m_body->GetPosition();
	//setPosition(pos.x, pos.y);




	float angle = m_body->GetAngle()* RAD2DEG;
	setRotation(angle);

	if (m_respawn == RESPAWNING)
	{
		setPosition(sf::Vector2f(-96, -2.f));
		m_body->SetLinearVelocity(b2Vec2(0.f, 0.f));
		m_respawn = WAITING;
		b2Vec2 pos = b2Vec2(-96, -2.f);
		setPosition(pos.x, pos.y);


	}
	else if (m_respawn == WAITING)
	{
		sf::sleep(sf::milliseconds(1000));
		m_respawn = RESPAWNED;
	}
	else
	{ 
		b2Vec2 pos = m_body->GetPosition();
		setPosition(pos.x, pos.y);
	}
}

void DynamicCircle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw((sf::CircleShape)*this); // Draw the Circle Shape

	// Add a line
	sf::RectangleShape line(sf::Vector2f(getRadius(), 0.01f));
	line.setPosition(getPosition());
	line.setOrigin(0.f, 0.005f);
	line.rotate(getRotation());
	target.draw(line);
}

void DynamicCircle::applyImpulse(b2Vec2 impulse)
{
	m_body->ApplyLinearImpulseToCenter(impulse, true);
}

void DynamicCircle::applyVelocity(b2Vec2 velocity)
{
	m_body->SetLinearVelocity(velocity);
}

void DynamicCircle::accel(b2Vec2 accel)
{

}

bool DynamicCircle::isStopped() const
{
	return m_stopped;
}


void DynamicCircle::respawn()
{

	if (m_respawn == RESPAWNED)
	{
		m_respawn = RESPAWNING;
	}
}



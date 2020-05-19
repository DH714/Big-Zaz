#pragma once

/*!
\file physicalObject.h
*/

#include <Box2D/Box2D.h>
#define DEG2RAD 0.017453f
#define RAD2DEG 57.29577f

/*!
\class PhysicalThing
\brief A simple class with common attributes and a few const values used in a few places.
*/
class PhysicalObject {
protected:
	b2Body * m_body = nullptr; //!< Box2D body, no need to delete this as BOX2D will look after it
	float mk_fDensity = 1.0f; //!< Density of the material - used to give mass
	float mk_fFriction = 0.1f; //!< Friction - I guess this is only friction from movement, not when static
	float mk_fRestitution = 0.8f; //!< Restitution - bouncyness of stuff
public:
	void setUserData(void* data) { m_body->SetUserData(data); }; //!< Set the userdata of the body
};

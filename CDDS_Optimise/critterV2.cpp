#include "CritterV2.h"

CritterV2::CritterV2(float speed) : m_speed(speed)
{

}

void CritterV2::update(GameObject& owner, float delta)
{
}

Component* CritterV2::clone()
{
	return new CritterV2(*this);
}

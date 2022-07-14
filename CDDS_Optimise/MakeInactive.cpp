#include "MakeInactive.h"

MakeInactive::MakeInactive(float delay) : m_delay(delay)
{
}

void MakeInactive::update(GameObject& owner, float delta)
{
	m_time += delta;
	if (m_time > m_delay)
	{
		owner.setActive(false);
	}
}

Component* MakeInactive::clone()
{
	return new MakeInactive(m_delay);
}

#include "InactiveAfter.h"

InactiveAfter::InactiveAfter(float delay) : m_delay(delay)
{
}

void InactiveAfter::update(GameObject& owner, float delta)
{
	m_time += delta;
	if (m_time > m_delay)
	{
		owner.setActive(false);
	}
}

Component* InactiveAfter::clone()
{
	return new InactiveAfter(m_delay);
}

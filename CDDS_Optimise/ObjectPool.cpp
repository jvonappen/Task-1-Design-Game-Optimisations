#include "ObjectPool.h"
#include "PlayMode.h"

ObjectPool::ObjectPool(PlayMode& mode, GameObjectPtr prototype, int cap) : m_mode(mode)
{
	m_prototype = prototype;
	for (int i = 0; i < cap; i++)
	{
		m_inactive.push_back(m_prototype->clone(glm::vec2{0,0}));
	}
}

GameObjectPtr ObjectPool::spawn()
{
	if (m_inactive.size() > 0)
	{
		auto object = m_inactive.back();
		m_inactive.pop_back();
		return object;
	}
	return nullptr;
}

void ObjectPool::despawn(GameObjectPtr object)
{

}

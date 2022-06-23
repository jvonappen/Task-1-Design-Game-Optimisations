#include "ObjectPool.h"
#include "PlayMode.h"
#include "TestMode.h"
#include <algorithm>

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
		object->setActive(true);
		m_inactive.pop_back();
		m_active.push_back(object);
		return object;
	}
	return nullptr;
}

void ObjectPool::despawn(GameObjectPtr object)
{
	
}

void ObjectPool::clean()
{
	for (auto& object : m_active)
	{
		if (!object->isActive())
		{
			m_inactive.push_back(object);
			m_mode.removeGameObject(object);
		}
	}
	m_active.erase(std::remove_if(
		m_active.begin(),
		m_active.end(),
		[](auto& object) {return !object->isActive(); }),
		m_active.end());
}
/*-------------------------------------------------------------------------*/

//ObjectPoolTM::ObjectPoolTM(TestMode& mode, GameObjectPtr prototype, int cap) : m_mode(mode)
//{
//	m_prototype = prototype;
//	for (int i = 0; i < cap; i++)
//	{
//		m_inactive.push_back(m_prototype->clone(glm::vec2{ 0,0 }));
//	}
//}
//
//GameObjectPtr ObjectPoolTM::spawn()
//{
//	if (m_inactive.size() > 0)
//	{
//		auto object = m_inactive.back();
//		object->setActive(true);
//		m_inactive.pop_back();
//		m_active.push_back(object);
//		return object;
//	}
//	return nullptr;
//}
//
//void ObjectPoolTM::despawn(GameObjectPtr object)
//{
//}
//
//void ObjectPoolTM::clean()
//{
//	for (auto& object : m_active)
//	{
//		if (!object->isActive())
//		{
//			m_inactive.push_back(object);
//			m_mode.removeGameObject(object);
//		}
//	}
//	m_active.erase(std::remove_if(
//		m_active.begin(),
//		m_active.end(),
//		[](auto& object) {return !object->isActive(); }),
//		m_active.end());
//}

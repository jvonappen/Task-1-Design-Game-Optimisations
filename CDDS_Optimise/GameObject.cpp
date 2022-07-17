#include "GameObject.h"
#include "Game.h"

void GameObject::update(float delta)
{
	for (auto iter : m_components)
	{
		iter.second->update(*this, delta);
	}
}

void GameObject::draw()
{
	for (auto iter : m_components)
	{
		iter.second->draw(*this);
	}
}

//void GameObject::addComponent(Component* component)
//{
//	m_components[component->getName()] = ComponentPtr(component);
//}

//ComponentPtr GameObject::getComponent(const char* name)
//{
//	auto iter = m_components.find(name);
//	if (iter != m_components.end())
//	{
//		return iter->second;
//	}		
//	return nullptr;
//}

//bool GameObject::hasComponent(const char* name)
//{
//	return m_components.find(name) != m_components.end();
//}

//void GameObject::removeComponent(const char* name)
//{
//	m_components.erase(name);
//}

GameObjectPtr GameObject::clone(const glm::vec2& position)
{
	GameObjectPtr clone = std::make_shared<GameObject>();
	clone->m_position = position;
	for (auto components : m_components)
	{
		clone->m_components[components.first] = std::shared_ptr<Component>(components.second->clone());
	}

	return clone;
}

#pragma once

#include <unordered_map> /* Hash Table */
#include <string>
#include <memory>
#include <glm/vec2.hpp>
#include <typeinfo>
#include <typeindex>

class GameObject;

class Component
{
public:
	virtual void update(GameObject& owner, float delta) {}
	virtual void draw(GameObject& owner) {}
	//virtual const char* getName() = 0;
	virtual Component* clone() { return nullptr; }
	virtual void onCollision(GameObject& owner, GameObject& other) {}
};
using ComponentPtr = std::shared_ptr<Component>;

class GameObject
{
public:
	void update(float delta);
	void draw();
											
	template<typename T>						 /*02:20*/
	T& addComponent(T* component)
	{ 
		m_components[std::type_index(typeid(T))] = ComponentPtr(component);
		return *component;
	}

	template<typename T>
	std::shared_ptr<T> getComponent()
	{
		auto iter = m_components.find(std::type_index(typeid(T)));
		if (iter != m_components.end())
		{
			return std::dynamic_pointer_cast<T>(iter->second);
		}
		return nullptr;
	}

	template<typename T>
	bool hasComponent()
	{
		return m_components.find(std::type_index(typeid(T))) != m_components.end();
	}

	template<typename T>
	void removeComponent()
	{
		m_components.erase(std::type_index(typeid(T))); /* may need adjustments*/
	}
	

	const glm::vec2& getPosition() const { return m_position; }
	void setPosition(const glm::vec2& position) { m_position = position; }

	const glm::vec2& getScale() const { return m_scale; }			
	void setScale(const glm::vec2& scale) { m_scale = scale; }

	float getRotation() const { return m_rotation; }
	void setRotation(float rotation) { m_rotation = rotation; }

	bool isActive() const { return m_active; } /*Flag*/
	void setActive(bool active) { m_active = active; }

	std::shared_ptr<GameObject> clone(const glm::vec2& position);

	glm::vec2 GetVelocity() { return m_velocity; }
	void SetVelocity(glm::vec2 velocity) { m_velocity = velocity; }


private:
	glm::vec2 m_position{0,0};
	glm::vec2 m_scale{1,1};
	float m_rotation{0};
	bool m_active{ true };

	std::unordered_map<std::type_index, ComponentPtr> m_components;

	glm::vec2 m_velocity {0, 0};
};

using GameObjectPtr = std::shared_ptr<GameObject>;
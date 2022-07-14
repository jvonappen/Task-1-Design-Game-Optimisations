#pragma once

#include <unordered_map> /* Hash Table */
#include <string>
#include <memory>
#include <glm/vec2.hpp>

class GameObject;

class Component
{
public:
	virtual void update(GameObject& owner, float delta) {}
	virtual void draw(GameObject& owner) {}
	virtual const char* getName() = 0;
	virtual Component* clone() { return nullptr; }
	virtual void onCollision(GameObject& owner, GameObject& other) {}
};
using ComponentPtr = std::shared_ptr<Component>;

class GameObject
{
public:
	void update(float delta);
	void draw();
													
	void addComponent(Component* component);
	ComponentPtr getComponent(const char* name);
	bool hasComponent(const char* name);
	void removeComponent(const char* name);
	/* ^^^ Could Template all of this ^^^ */

	const glm::vec2& getPosition() const { return m_position; }
	void setPosition(const glm::vec2& position) { m_position = position; }

	const glm::vec2& getScale() const { return m_scale; }			
	void setScale(const glm::vec2& scale) { m_scale = scale; }

	float getRotation() const { return m_rotation; }
	void setRotation(float rotation) { m_rotation = rotation; }

	bool isActive() const { return m_active; } /*Flag*/
	void setActive(bool active) { m_active = active; }

			

	std::shared_ptr<GameObject> clone(const glm::vec2& position);


private:
	glm::vec2 m_position{0,0};
	glm::vec2 m_scale{1,1};
	float m_rotation{0};
	bool m_active{ true };

	std::unordered_map<std::string, ComponentPtr> m_components;

};

using GameObjectPtr = std::shared_ptr<GameObject>;
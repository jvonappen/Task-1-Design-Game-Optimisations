#pragma once

#include "GameObject.h"
#include "raylib.h"
#include <glm/vec2.hpp>

class Sprite : public Component
{
public:
	Sprite(Texture2D texture);
	void draw(GameObject& owner) override;

	const char* getName() override { return "Sprite"; }

	Component* clone() override { return new Sprite(*this); }

private:
	Texture2D m_texture;
	glm::ivec2 m_size;
	glm::vec2 m_origin {0.5f, 0.5f};
	Color m_tint{RAYWHITE};
	
};


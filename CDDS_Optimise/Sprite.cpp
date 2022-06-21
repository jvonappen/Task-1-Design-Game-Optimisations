#include "Sprite.h"

Sprite::Sprite(Texture2D texture) : m_texture(texture)
{
	m_size.x = texture.width;
	m_size.y = texture.height;
}

void Sprite::draw(GameObject& owner)
{
	auto& pos = owner.getPosition();
	glm::vec2 size = owner.getScale();
	size *= m_size;
	glm::vec2 origin = size * m_origin;

	DrawTexturePro(m_texture,
		Rectangle{ 0, 0, (float)m_size.x, (float)m_size.y },
		Rectangle{ pos.x, pos.y, size.x, size.y },
		Vector2{ origin.x, origin.y },
		owner.getRotation(),
		m_tint);
}

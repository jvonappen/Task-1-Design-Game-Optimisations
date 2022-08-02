#pragma once
#include "raymath.h"

class AABB
{
public:
	AABB(Vector2 centre, Vector2 halfSize);

	bool contains(Vector2 point);
	bool intersects(AABB other);

private:
	Vector2 m_centre;
	Vector2 m_halfSize;
};


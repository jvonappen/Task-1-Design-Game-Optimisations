//#pragma once
//#include "GameObject.h"
//#include "raylib.h"
//#include "Game.h"
//#include "PlayMode.h"
//
//class CritterV2 : public Component
//{
//public:
//	CritterV2(PlayMode& mode);
//	auto Critters();
//
//	void update(GameObject& owner, float delta) override;
//	const char* getName() override { return "CritterV2"; }
//	Component* clone() override;
//
//	float GetX() { return m_position.x; }
//	float GetY() { return m_position.y; }
//	void SetX(float x) { m_position.x = x; }
//	void SetY(float y) { m_position.y = y; }
//
//	Vector2 GetPosition() { return m_position; }
//	void SetPosition(Vector2 position) { m_position = position; }
//
//	Vector2 GetVelocity() { return m_velocity; }
//	void SetVelocity(Vector2 velocity) { m_velocity = velocity; }
//
//	float GetRadius() { return m_radius; }
//
//	bool IsDirty() { return m_isDirty; }
//	void SetDirty() { m_isDirty = true; }
//
//	bool IsDead() { return m_isLoaded == false; }
//
//	int critters[1000];
//
//private:
//	float m_speed;
//	PlayMode& m_mode;
//
//	Vector2 m_position;
//	Vector2 m_velocity;
//	float m_radius;
//	bool m_isLoaded;
//	bool m_isDirty;		// indicates if we've already processed a collision response for this critter
//
//
//};


//#include "CritterV2.h"
//
//#include "raymath.h"
//#include <random>
//#include <time.h>
//#include "Critter.h"
//
//
//CritterV2::CritterV2(PlayMode& mode) : m_mode(mode)
//{
//	
//}
//
//auto CritterV2::Critters()
//{
//	m_position = Vector2{ 0, 0 };
//	m_velocity = Vector2{ 0, 0 };
//	m_radius = 0;
//	m_isLoaded = false;
//}
//
//void CritterV2::update(GameObject& owner, float delta)
//{
//	/* Put critter movements in here */
//	srand(time(NULL));
//
//	Critter critters[1000];
//
//	// create some critters
//	const int CRITTER_COUNT = 50;         /* 50 */
//	const int MAX_VELOCITY = 80;
//
//	for (int i = 0; i < CRITTER_COUNT; i++)
//	{
//		// create a random direction vector for the velocity
//		Vector2 velocity = { -100 + (rand() % 200), -100 + (rand() % 200) };
//		// normalize and scale by a random speed
//		velocity = Vector2Scale(Vector2Normalize(velocity), MAX_VELOCITY);
//
//		//check each critter against screen bounds
//		if (critters[i].GetX() < 0) {
//			critters[i].SetX(0);
//			critters[i].SetVelocity(Vector2{ -critters[i].GetVelocity().x, critters[i].GetVelocity().y });
//		}
//		if (critters[i].GetX() > GetScreenWidth()) {
//			critters[i].SetX(GetScreenWidth());
//			critters[i].SetVelocity(Vector2{ -critters[i].GetVelocity().x, critters[i].GetVelocity().y });
//		}
//		if (critters[i].GetY() < 0) {
//			critters[i].SetY(0);
//			critters[i].SetVelocity(Vector2{ critters[i].GetVelocity().x, -critters[i].GetVelocity().y });
//		}
//		if (critters[i].GetY() > GetScreenHeight()) {
//			critters[i].SetY(GetScreenHeight());
//			critters[i].SetVelocity(Vector2{ critters[i].GetVelocity().x, -critters[i].GetVelocity().y });
//		}
//	}
//}
//
////Component* CritterV2::clone()
////{
////	return new CritterV2(*this);
////}

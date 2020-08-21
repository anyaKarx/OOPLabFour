#pragma once
#include "Rectangle.h"
#include "Ring.h"

static class CollisionManager
{
public:
	static bool IsCollisionRectangle(Rectangle& first, Rectangle& second);
	static bool IsCollisionRing(Ring& first, Ring& second);
	static void DemoCollision();
};
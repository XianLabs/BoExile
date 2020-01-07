#pragma once
#include <Windows.h>
#include <stdint.h>
#include <math.h>
#include "Structures.hpp"

static class MathHelper
{
private:

public:
	static BOOL IsPointInCircle(FLOAT centerX, FLOAT centerY, FLOAT x, FLOAT y);
	static BOOL IsPointInCircle(FLOAT centerX, FLOAT centerY, FLOAT x, FLOAT y, float radius);
	static BOOL IsInRectangle(FLOAT centerX, FLOAT centerY, FLOAT x, FLOAT y);
	static BOOL IsInRectangle(FLOAT centerX, FLOAT centerY, FLOAT x, FLOAT y, float radius);
	static int RandomWithLimit(int limit);
	static short changeEndianness16(short val);
	static __int32 changeEndianness32(__int32 val);
	static uint32_t htonl(uint32_t value);
	static int GetDistanceBetweenObjects(int x_A, int y_A, int x_B, int y_B);
	static float AngleBetween(Vector2 v1, Vector2 v2);
};

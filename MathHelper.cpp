#include "MathHelper.hpp"

#define NEARBY_RADIUS 250.0f;

BOOL MathHelper::IsInRectangle(FLOAT centerX, FLOAT centerY, FLOAT x, FLOAT y)
{
	FLOAT radius = NEARBY_RADIUS;

	return x >= centerX - radius && x <= centerX + radius &&
		y >= centerY - radius && y <= centerY + radius;
}

//test if coordinate (x, y) is within a radius from coordinate (center_x, center_y)
BOOL MathHelper::IsPointInCircle(FLOAT centerX, FLOAT centerY, FLOAT x, FLOAT y)
{
	FLOAT radius = NEARBY_RADIUS;

	if (MathHelper::IsInRectangle(centerX, centerY, x, y))
	{
		FLOAT dx = centerX - x;
		FLOAT dy = centerY - y;
		dx *= dx;
		dy *= dy;
		FLOAT distanceSquared = dx + dy;
		FLOAT radiusSquared = radius * radius;
		return distanceSquared <= radiusSquared;
	}
	return FALSE;
}

BOOL MathHelper::IsPointInCircle(FLOAT centerX, FLOAT centerY, FLOAT x, FLOAT y, float radius)
{
	if (MathHelper::IsInRectangle(centerX, centerY, x, y, radius))
	{
		FLOAT dx = centerX - x;
		FLOAT dy = centerY - y;
		dx *= dx;
		dy *= dy;
		FLOAT distanceSquared = dx + dy;
		FLOAT radiusSquared = radius * radius;
		return distanceSquared <= radiusSquared;
	}
	return FALSE;
}

BOOL MathHelper::IsInRectangle(FLOAT centerX, FLOAT centerY, FLOAT x, FLOAT y, float radius)
{
	return x >= centerX - radius && x <= centerX + radius &&
		y >= centerY - radius && y <= centerY + radius;
}

int MathHelper::RandomWithLimit(int limit) 
{
	/* return a random number between 0 and limit inclusive.
	*/

	int divisor = RAND_MAX / (limit + 1);
	int retval;

	do {
		retval = rand() / divisor;
	} while (retval > limit);

	return retval;
}

short MathHelper::changeEndianness16(short val)
{
	return (val << 8) |          // left-shift always fills with zeros
		((val >> 8) & 0x00ff); // right-shift sign-extends, so force to zero
}

__int32 MathHelper::changeEndianness32(__int32 val)
{
	union bytes4
	{
		__int32 value;
		char ch[4];
	};


	bytes4 temp;
	temp.value = val;
	char x;

	x = temp.ch[0];
	temp.ch[0] = temp.ch[1];
	temp.ch[1] = x;

	x = temp.ch[2];
	temp.ch[2] = temp.ch[3];
	temp.ch[3] = x;
	return temp.value;
}

uint32_t MathHelper::htonl(uint32_t value)
{
	long lValue1 = value;
	long lValue2 = 0;

	lValue2 |= (lValue1 & 0xFF000000) >> 24;
	lValue2 |= (lValue1 & 0x00FF0000) >> 8;
	lValue2 |= (lValue1 & 0x0000FF00) << 8;
	lValue2 |= (lValue1 & 0x000000FF) << 24;

	return lValue2;
}

int MathHelper::GetDistanceBetweenObjects(int x_A, int y_A, int x_B, int y_B)
{
	double resultX = pow((double)(x_B - x_A), 2);
	double resultY = pow((double)(y_B - y_A), 2);
	double FinalResult = sqrt(resultX + resultY);
	return (int)FinalResult;
}

FLOAT MathHelper::AngleBetween(Vector2 v1, Vector2 v2)
{
	float len1 = sqrt((FLOAT)(v1.X * v1.X + v1.Y * v1.Y));
	float len2 = sqrt((FLOAT)(v2.X * v2.X + v2.Y * v2.Y));

	float dot = v1.X * v2.X + v1.Y * v2.Y;

	float a = dot / (len1 * len2);

	if (a >= 1.0)
		return 0.0;
	else if (a <= -1.0)
		return 3.14;
	else
		return acos(a); // 0..PI
}
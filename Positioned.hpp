#pragma once
#include "CComponent.hpp"
#include "Entity.hpp"

class Positioned : CComponent
{
private:

	Vector2 v2; //0xE8, 0xEC
	Vector3 v3; //0x114, 0x118
	byte Reaction; //0x58

	float Rotation; 
	float RotationDegrees = Rotation * (180/3.14); //Rotation * (180/pi)

	float CharacterSize; //0x100

public:

	static VOID SetEntitySize(Entity* e, float size);
	static VOID SetEntityPosition(Entity* e, Vector2 v2);

};
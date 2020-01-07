#pragma once
#include <Windows.h>
#include <string>


enum Directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NORTH_WEST,
	NORTH_EAST,
	SOUTH_WEST,
	SOUTH_EAST,
	WAYPOINT_INTERACTION,
	AREA_TRANSITION,
	TOWN,
	NONE,
};

class PathFinder
{
private:
	UINT16 CurrentArea;
	UINT16 DestinationArea;
	Directions PathDirection;

public:
	VOID SetPathDirection(Directions d);
	VOID SetDestinationArea(UINT16 Area);
	VOID SetArea(UINT16 AreaID);
	
	Directions DeterminePathByMap(UINT16 Area);
	
	UINT16 GetCurrentArea();
	UINT16 GetDestinationArea();
	Directions GetPathDirection();

};
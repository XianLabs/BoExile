#include "PathFinder.hpp"
#include "AreaTransition.hpp"

Directions PathFinder::DeterminePathByMap(UINT16 Area)
{
	if (Area == 0)
		return NONE;

	if (Area == 132)
	{
		//set destination area back to highgate to enter portal at end
		printf("Detected blood aquaduct... Path: North west\n");
		SetPathDirection(NORTH_WEST);
		return NORTH_WEST;
	}
	else if (Area == 133)
	{
		if (GetDestinationArea() == 132)
		{
			SetPathDirection(WAYPOINT_INTERACTION);
			printf("Path direction: Waypoint\n");
			return WAYPOINT_INTERACTION;
		}
	}

	return NONE;
}

VOID PathFinder::SetPathDirection(Directions d)
{
	this->PathDirection = d;
}

VOID PathFinder::SetArea(UINT16 Area)
{
	this->CurrentArea = Area;
}

VOID PathFinder::SetDestinationArea(UINT16 Area)
{
	this->DestinationArea = Area;
}

UINT16 PathFinder::GetCurrentArea()
{
	return this->CurrentArea;
}

UINT16 PathFinder::GetDestinationArea()
{
	return this->DestinationArea;
}

Directions PathFinder::GetPathDirection()
{
	return this->PathDirection;
}
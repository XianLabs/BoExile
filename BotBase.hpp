#pragma once
#include "LocalActor.hpp"
#include "Hacks.hpp"
#include "NetLogger.hpp"
#include "PathFinder.hpp"

#define BotType int
#define FONT_BLACK 30 | 40
#define FONT_RED 31 | 41
#define FONT_GREEN 32 | 42
#define FONT_YELLOW 33 | 43
#define FONT_BLUE 34 | 44
#define FONT_MAGENTA 35 | 45
#define FONT_CYAN 36 | 46
#define FONT_WHITE 37 | 47
#define FONT_BRI_BLACK 90 | 100
#define FONT_BRI_RED 91 | 101
#define FONT_BRI_GREEN 92 | 102
#define FONT_BRI_YELLOW 93 | 103
#define FONT_BRI_BLUE 94 | 104
#define FONT_BRI_MAGENTA 95 | 105
#define FONT_BRI_CYAN 96 | 106
#define FONT_BRI_WHITE 97 | 107

class BotBase
{
	friend class MappingBot;
public:

	static BotBase* GetInstance();
	static void setType(BotType t)
	{
		Type = t;
		delete BotInstance;
		BotInstance = 0;
	}

	LocalActor* GetActor() { return this->LocalEntity; }
	NetLogger* GetNetSender() { return this->NetSender; }

private:

	static BotBase *BotInstance;
	static BotType Type;

	std::list<Entity> InventoryItems;
	
	LocalActor* LocalEntity;
	NetLogger* NetSender;

protected:
	int Value;
	BotBase()
	{
		LocalEntity = new LocalActor();
		InventoryItems = std::list<Entity>();
		NetSender = new NetLogger();
	}
};


class MappingBot : public BotBase
{
private:

	std::list<Entity> MonsterList;
	std::list<Entity> GroundItems;

public:

	PathFinder* ActorPath;
	int GetAreasCompleted();
	std::list<Entity> GetMonsterList() { return this->MonsterList; }

	static VOID HandleClientTxtLogs(char* OutBuffer, int NumBytesOut);
	static VOID HandleEntitySpawn(UINT64 EntityWrapperPtr);
	static VOID HandleWorldItem(Entity* e);
	static VOID HandleItemList();
	static VOID HandleMonsterSpawn(Entity* e, MappingBot* mb);
	static VOID HandleNearbyMonsters();
	static VOID HandleAreaTransition(Entity* e);
	static VOID HandleCurrentHPMP();
	static VOID HandlePathfinding();
	
	static VOID PrettyPrintEntity(Entity* e);

	static VOID MonitorCharacterHealthMana();

	VOID DecideDestination(Directions CurrentDirection, Directions DestinationDirection);

	HANDLE MonsterTrackingThread; //lazy atm to make private
	HANDLE ItemTrackingThread;
	HANDLE PathfindingThread;
	HANDLE LifeTrackingThread;

	UINT32 WaypointEntityID;
	UINT32 AreaTransitionID;

	BOOL isTrackingMonsters;
	BOOL isAutoFlasking;
	BOOL isAutoLooting;
	BOOL isAutoMapping;
	BOOL isAttacking;
	BOOL isLooting;
	BOOL isMoving;

	std::string AreaMappings[255];
	VOID InitializeAreaMappings(); //finish this shit
	std::string GetMapNameByIndex(int index);
	int GetMapIndexByName(std::string name);

	USHORT MainAttackSkillID;
	BOOL IsMelee;
	BOOL ReviveOnDeath;
	BOOL ReviveCheckpointOrTown; 


protected:
	friend class BotBase;
	MappingBot()
	{
		this->ActorPath = new PathFinder();
		
		this->MonsterList = std::list<Entity>();
		this->GroundItems = std::list<Entity>();
		
		this->MonsterTrackingThread = NULL;
		this->ItemTrackingThread = NULL;
		this->PathfindingThread = NULL;
		this->LifeTrackingThread = NULL;
		
		this->WaypointEntityID = 0;
		this->AreaTransitionID = 0;
			
		this->isAutoFlasking = FALSE;
		this->isAutoLooting = FALSE;
		this->isLooting = FALSE;
		this->isAutoMapping = FALSE;
		this->isAttacking = FALSE;
		this->isTrackingMonsters = FALSE;
		this->isMoving = FALSE;
		this->MainAttackSkillID = 0;
		this->IsMelee = TRUE; //melee by default
		this->ActorPath->SetPathDirection(Directions::NONE);
		this->ReviveOnDeath = FALSE;
		this->ReviveCheckpointOrTown = FALSE;
		
		InitializeAreaMappings();

	}

};
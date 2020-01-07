#include "BotBase.hpp"
#include "Chest.hpp"
#include "Player.hpp"
#include "Life.hpp"
#include "FileIO.hpp"
#include "AreaTransition.hpp"
#include "Targetable.hpp"
#include "PacketBuilder.hpp"
#include "MathHelper.hpp"
BOOL IsLoggingComponents = FALSE;

BotBase *BotBase::GetInstance()
{
	if (!BotInstance)
		if (Type == 0)
			BotBase::BotInstance = new BotBase();
		else if (Type == 1)
			BotInstance = new MappingBot();

	return BotInstance;
}

VOID MappingBot::HandlePathfinding() //clean this bloat up once initial testing is good
{
	MappingBot* mb = (MappingBot*)BotInstance->GetInstance();
	Directions Path = mb->ActorPath->GetPathDirection();

	if (Path == Directions::NONE)
	{
		Path = mb->ActorPath->DeterminePathByMap(mb->ActorPath->GetCurrentArea());
		mb->ActorPath->SetPathDirection(Path);
	}

	int EvenOdd = 0;

	while (Path != Directions::NONE && mb->isAutoMapping)
	{
		Sleep(150);
		Path = mb->ActorPath->GetPathDirection();		
		EvenOdd += MathHelper::RandomWithLimit(7);

		switch (Path) //need to fix this up
		{
			case Directions::NONE:
			{
				Directions NewPath = mb->ActorPath->DeterminePathByMap(mb->ActorPath->GetCurrentArea());
				mb->ActorPath->SetPathDirection(NewPath);
			}break;

			case Directions::WAYPOINT_INTERACTION:
			{
				printf("Sending movement to waypoint...\n");
				Sleep(5000);
				mb->LocalEntity->CreateNewInstance(0x8BEA, mb->WaypointEntityID); //change this from BA to destination map hash
				mb->ActorPath->SetPathDirection(mb->ActorPath->DeterminePathByMap(mb->ActorPath->GetCurrentArea()));
				mb->isTrackingMonsters = TRUE;
			}break;

			case Directions::NORTH_WEST:
			{
				if (!mb->isAttacking && !mb->isLooting && !mb->isMoving)
				{
					Entity* e = LocalActor::GetEntityFromCharacterBasePtr();
					Vector2* PlayerV = Entity::GetEntityGridPosition(e);
					INT StartX = PlayerV->X;
					INT StartY = PlayerV->Y;

					if (PlayerV != NULL)
					{
						mb->isMoving = TRUE;
						printf("Moving: %d, %d\n", PlayerV->X, PlayerV->Y + 65);
						PlayerV->Y += 65;
						mb->GetActor()->SendActionAndWaitForCooldown(0x2909, 0, PlayerV);
						mb->isMoving = FALSE;
					}

					Vector2* PlayerV2 = Entity::GetEntityGridPosition(e);
					if (PlayerV2 != NULL)
					{
						if (StartX == PlayerV2->X && StartY == PlayerV2->Y)
						{
							if (EvenOdd % 2 != 0)
							{
								printf("Changing path to SOUTH WEST.\n");
								mb->ActorPath->SetPathDirection(SOUTH_WEST);
							}
							else
							{
								printf("Changing path to NORTH EAST.\n");
								mb->ActorPath->SetPathDirection(NORTH_EAST);
							}
						}
					}
					
					delete PlayerV2;
					delete PlayerV;
					delete e;
					e = nullptr;
					PlayerV = nullptr;
					PlayerV2 = nullptr;
				}
			}break;

			case Directions::SOUTH_EAST:
			{
				if (!mb->isAttacking && !mb->isLooting && !mb->isMoving)
				{
					Entity* e = LocalActor::GetEntityFromCharacterBasePtr();
					Vector2* PlayerV = Entity::GetEntityGridPosition(e);
					INT StartX = PlayerV->X;
					INT StartY = PlayerV->Y;

					if (PlayerV != NULL)
					{
						mb->isMoving = TRUE;
						printf("Moving: %d, %d\n", PlayerV->X, PlayerV->Y - 65);
						PlayerV->Y -= 65;
						mb->GetActor()->SendActionAndWaitForCooldown(0x2909, 0, PlayerV);
						mb->isMoving = FALSE;
					}

					Vector2* PlayerV2 = Entity::GetEntityGridPosition(e);
					if (PlayerV2 != NULL)
					{
						if (StartX == PlayerV2->X && StartY == PlayerV2->Y)
						{
							printf("Changing path to NORTH WEST.\n");
							mb->ActorPath->SetPathDirection(NORTH_WEST);
						}
					}

					delete PlayerV2;
					delete PlayerV;
					delete e;
					e = nullptr;
					PlayerV = nullptr;
					PlayerV2 = nullptr;
				}
			}break;

			case Directions::SOUTH_WEST:
			{
				if (!mb->isAttacking && !mb->isLooting && !mb->isMoving)
				{
					Entity* e = LocalActor::GetEntityFromCharacterBasePtr();
					Vector2* PlayerV = Entity::GetEntityGridPosition(e);
					INT StartX = PlayerV->X;
					INT StartY = PlayerV->Y;

					if (PlayerV != NULL)
					{
						mb->isMoving = TRUE;
						printf("Moving: %d, %d\n", PlayerV->X-75, PlayerV->Y);
						PlayerV->X -= 65;
						mb->GetActor()->SendActionAndWaitForCooldown(0x2909, 0, PlayerV);
						mb->isMoving = FALSE;
					}

					Vector2* PlayerV2 = Entity::GetEntityGridPosition(e);
					if (PlayerV2 != NULL)
					{
						if (StartX == PlayerV2->X && StartY == PlayerV2->Y)
						{
							printf("Changing path to NORTH WEST.\n");
							mb->ActorPath->SetPathDirection(NORTH_WEST);
						}
					}

					delete PlayerV2;
					delete PlayerV;
					delete e;
					e = nullptr;
					PlayerV = nullptr;
					PlayerV2 = nullptr;
				}
			}break;

			case Directions::NORTH_EAST:
			{
				if (!mb->isAttacking && !mb->isLooting && !mb->isMoving)
				{
					Entity* e = LocalActor::GetEntityFromCharacterBasePtr();
					Vector2* PlayerV = Entity::GetEntityGridPosition(e);
					INT StartX = PlayerV->X;
					INT StartY = PlayerV->Y;

					if (PlayerV != NULL)
					{
						mb->isMoving = TRUE;
						printf("Moving: %d, %d\n", PlayerV->X + 75, PlayerV->Y);
						PlayerV->X += 65;
						mb->GetActor()->SendActionAndWaitForCooldown(0x2909, 0, PlayerV);
						mb->isMoving = FALSE;
					}

					Vector2* PlayerV2 = Entity::GetEntityGridPosition(e);
					if (PlayerV2 != NULL)
					{
						if (StartX == PlayerV2->X && StartY == PlayerV2->Y)
						{
							printf("Changing path to NORTH WEST.\n");
							mb->ActorPath->SetPathDirection(NORTH_WEST);
						}
					}

					delete PlayerV2;
					delete PlayerV;
					delete e;
					e = nullptr;
					PlayerV = nullptr;
					PlayerV2 = nullptr;
				}
			}break;

			case Directions::AREA_TRANSITION:
			{
				while (mb->isAttacking || mb->isLooting || mb->isMoving)
				{
					Sleep(100);
				}

				//we need to move closer to it.
				Entity* e = LocalActor::GetEntityFromCharacterBasePtr();
				Vector2* PlayerV2 = Entity::GetEntityGridPosition(e);

				if (PlayerV2 != NULL)
				{
					PlayerV2->Y += 65;
					PlayerV2->X -= 65;
					printf("Sending movement to AreaTransition...\n");
					mb->isMoving = TRUE;
					mb->GetActor()->SendActionAndWaitForCooldown(0x2909, 0, PlayerV2);
					Sleep(2000);
					mb->GetActor()->SendActionAndWaitForCooldown(0x0266, mb->AreaTransitionID, 0);
					Sleep(3000);
					mb->isMoving = FALSE;
				}

				delete PlayerV2;
				delete e;
				e = nullptr; PlayerV2 = nullptr;
			}break;

			case Directions::TOWN:
			{
				//mb->MonsterList.clear();
				//mb->GroundItems.clear();
				mb->AreaTransitionID = 0;
				mb->isTrackingMonsters = FALSE;
				
				//TerminateThread(mb->MonsterTrackingThread, 0); mb->MonsterTrackingThread = NULL;
				//TerminateThread(mb->ItemTrackingThread, 0); mb->ItemTrackingThread = NULL;
				//TerminateThread(mb->LifeTrackingThread, 0); mb->LifeTrackingThread = NULL;
							
				Sleep(5000);
				mb->isMoving = TRUE;
				
				printf("In town!\n");
				Directions NewPath = mb->ActorPath->DeterminePathByMap(mb->ActorPath->GetCurrentArea());
				mb->ActorPath->SetPathDirection(NewPath);

				if (mb->ActorPath->GetCurrentArea() == 133)
				{
					Vector2* v2 = new Vector2();
					if (v2 != NULL)
					{
						v2->X = 170;
						v2->Y = 473;
						mb->GetActor()->SendActionAndWaitForCooldown(0x2909, 0, v2);
						Sleep(3000);
						delete v2; v2 = nullptr;

					}
				}

				mb->isMoving = FALSE;

			}break;

		};
	}

	mb->PathfindingThread = NULL;
}

VOID MappingBot::HandleEntitySpawn(UINT64 EntityWrapperPtr) //Might need to put this into botbase
{
	Entity* e = new Entity();

	e->SetInfo(EntityWrapperPtr);
	e->GetComponentList();
	std::wstring w = e->GetFilePathFromMemory(EntityWrapperPtr);

	if (IsLoggingComponents)
	{
		for each (ComponentListNode c in e->GetComponentList())
		{
			UINT64 ComponentAddress = e->GetComponentAddress((char*)c.NamePtr);
			printf("Component: %s, Address: %llX\n", c.NamePtr, ComponentAddress);
		}
	}

	//Begin decision making based on spawn
	if (wcscmp(w.c_str(), L"Metadata/MiscellaneousObjects/WorldItem") == 0)
	{
		MappingBot::HandleWorldItem(e);
	}
	else if (wcsstr(w.c_str(), L"Metadata/Monsters/") != NULL)
	{
		if (!FileHasLineW(L"BoE/IgnoredMonsters.txt", (wchar_t*)w.c_str()))
		{
			MappingBot::HandleMonsterSpawn(e, (MappingBot*)BotBase::GetInstance());
		}
	}
	else if (wcsstr(w.c_str(), L"Objects/AreaTransition") != NULL)
	{	
		MappingBot::HandleAreaTransition(e);
	}
	else if (wcsstr(w.c_str(), L"Waypoint") != NULL)
	{
		MappingBot* mb = (MappingBot*)BotBase::GetInstance();
		mb->WaypointEntityID = e->GetEntityID();
		printf("WaypointID: %x\n", mb->WaypointEntityID);
	}
	else
		PrettyPrintEntity(e);
	
	delete e;
	e = nullptr;
}

VOID MappingBot::HandleClientTxtLogs(char* OutBuffer, int NumBytesOut)
{
	std::string strBuff = std::string(OutBuffer);

	if (strstr(OutBuffer, "An unexpected disconnect")) //relog thread
	{
		
	}
	else if (strstr(OutBuffer, "You have entered ") != NULL) //clear mob list + ground items list at each new map
	{
		MappingBot* mb = (MappingBot*)BotInstance->GetInstance();
		printf("%s\n", OutBuffer);
		std::size_t pos = strBuff.find("entered ");
		std::string subStr = strBuff.substr(pos + 8, 255);
		std::size_t posEnd = subStr.find(".");
		std::string finalStr = subStr.substr(0, posEnd);

		mb->MonsterList.clear(); //check this
		mb->GroundItems.clear();

		if (finalStr.compare("Highgate") == 0)
		{
			mb->ActorPath->SetArea(mb->GetMapIndexByName(finalStr));
			mb->ActorPath->SetDestinationArea(mb->GetMapIndexByName(finalStr) - 1);
			mb->ActorPath->SetPathDirection(TOWN);
		}			
		else if (finalStr.compare("The Blood Aqueduct") == 0)
		{
			mb->ActorPath->SetArea(mb->GetMapIndexByName(finalStr));
			mb->ActorPath->SetDestinationArea(mb->GetMapIndexByName(finalStr) + 1);
		}
		else
		{
			mb->ActorPath->SetArea(65535);
			mb->ActorPath->SetDestinationArea(65535);
		}
		if (mb->isAutoMapping && mb->PathfindingThread == NULL)
		{
			mb->PathfindingThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&MappingBot::HandlePathfinding, 0, 0, 0);
		}
	}
}


VOID MappingBot::HandleWorldItem(Entity* e)
{	
	MappingBot* mb = (MappingBot*)BotInstance->GetInstance();

	UINT64 Addr = e->GetComponentAddress("WorldItem");
	Entity* Item = e->GetSubObjectEntity(Addr, "WorldItem");
	std::wstring w = Item->GetFilePathFromMemory(Item->GetMemoryAddress());
	
	if (FileHasLineW(L"BoE/Items.txt", (wchar_t*)w.c_str())) //add to list
	{		
		wprintf(L"Found desired item: %s\n", w.c_str());
		
		BOOL IsInList = FALSE;

		//compare entity ID to our current list to see if it's there as entities can spawn + despawn in and out of range of char
		std::list<Entity>::const_iterator iterator;
		for (iterator = mb->GroundItems.begin(); iterator != mb->GroundItems.end(); ++iterator)
		{
			UINT32 ID = iterator._Ptr->_Myval.GetEntityID();

			if (ID == e->GetEntityID())
				IsInList = TRUE;
		}

		if (IsInList == FALSE)
		{
			if (e->GetEntityID() != 0)
			{
				Entity AddedItem = Entity();
				AddedItem.SetInfo(e->GetMemoryAddress());

				mb->GroundItems.push_back(AddedItem);

				//ned thread
				if (mb->ItemTrackingThread == NULL && mb->isAutoLooting)
				{
					printf("Starting item tracking thread...\n");
					mb->ItemTrackingThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&MappingBot::HandleItemList, 0, 0, 0);
				}
			}
		}
	}

	delete Item;
	Item = nullptr;
	
}


VOID MappingBot::HandleItemList()
{
	MappingBot* mb = (MappingBot*)BotInstance->GetInstance();

	while (1)
	{
		if (mb->GroundItems.size() > 0 && mb->isAutoLooting)
		{
			std::list<Entity>::const_iterator iterator;
			
			for (iterator = mb->GroundItems.begin(); iterator != mb->GroundItems.end(); ++iterator)
			{
				Entity* e = LocalActor::GetEntityFromCharacterBasePtr();
				Vector2* PlayerV = Entity::GetEntityGridPosition(e);
				Vector2* ItemV = Entity::GetEntityGridPosition(&iterator._Ptr->_Myval);

				if (ItemV != NULL && PlayerV != NULL)
				{
					if (MathHelper::IsPointInCircle((FLOAT)PlayerV->X, (FLOAT)PlayerV->Y, (FLOAT)ItemV->X, (FLOAT)ItemV->Y, 75.0))
					{						
						while (mb->isAttacking || mb->isMoving || mb->isLooting)
							Sleep(50);

						mb->isLooting = TRUE;
						printf("Looting item: %x\n", iterator._Ptr->_Myval.GetEntityID());
						mb->GetActor()->SendActionAndWaitForCooldown(0x0266, iterator._Ptr->_Myval.GetEntityID(), 0);
						mb->GroundItems.erase(iterator);
						mb->isLooting = FALSE;
					}
				}
				else
					mb->GroundItems.erase(iterator);


				delete e;
				delete PlayerV;
				delete ItemV;
				e = nullptr;
				PlayerV = nullptr;
				ItemV = nullptr;		
			}
		}
	}

	mb->ItemTrackingThread = NULL;
}

VOID MappingBot::PrettyPrintEntity(Entity* e) //clean up this cancer
{
	std::wstring w = e->GetFilePathFromMemory(e->GetMemoryAddress());
	Vector2* GridLocation = Entity::GetEntityGridPosition(e);
	UINT32 EntityID = e->GetEntityID();

	if (wcsstr(w.c_str(), L"Unique") != NULL) //make this more portable
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_INTENSITY | FOREGROUND_RED));
		wprintf(L"**UNIQUE CHEST DETECTED**: (%d, %d) Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15)); // 0 or 15 = 15 (0 / 11111)
	}
	else if (wcsstr(w.c_str(), L"FossilChest") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_INTENSITY | FOREGROUND_RED));
		wprintf(L"**FOSSIL CHEST DETECTED**: (%d, %d) Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"Resonator3") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_INTENSITY | FOREGROUND_RED));
		wprintf(L"**RESONATOR CACHE DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"Resonator4") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_INTENSITY | FOREGROUND_RED));
		wprintf(L"**RESONATOR HOARDE!!! DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"Divination") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_INTENSITY | FOREGROUND_RED));
		wprintf(L"**DIVINATION CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"Divination") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_BLUE));
		wprintf(L"**DIVINATION CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"OffPathCurrency") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_GREEN));
		wprintf(L"**OFFPATH CURRENCY CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"DynamiteCurrency") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_GREEN));
		wprintf(L"**DYNAMITE CURRENCY2 CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"DynamiteCurrency2") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_GREEN));
		wprintf(L"**DYNAMITE CURRENCY CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"EternalChest") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_GREEN));
		wprintf(L"**DYNAMITE CURRENCY CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"LegionChests/KaruiChest") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_RED));
		wprintf(L"**KARUI LEGION CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"LegionChests/EternalEmpireChest") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_GREEN));
		wprintf(L"**ETERNAL LEGION CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"LegionChests/VaalChest") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_GREEN));
		wprintf(L"**VAAL LEGION CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else if (wcsstr(w.c_str(), L"LegionChests/TemplarChest") != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_GREEN));
		wprintf(L"**TEMPLAR LEGION CHEST DETECTED**: (%d, %d)  Path: %s\n", GridLocation->X, GridLocation->Y, w.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 | 15));
	}
	else 
	{
		//wprintf(L"Generic Entity, Path: %s, ID: %x, Location: (%d,%d)\n", w.c_str(), EntityID, GridLocation->X, GridLocation.Y);
	}

	delete GridLocation;
	GridLocation = nullptr;
}

VOID MappingBot::HandleMonsterSpawn(Entity* e, MappingBot* b)
{
	Entity* LocalEnt = LocalActor::GetEntityFromCharacterBasePtr();
	Vector2* PlayerV = Entity::GetEntityGridPosition(LocalEnt);
	Vector2* MonsterV = Entity::GetEntityGridPosition(e);

	BOOL IsInList = FALSE;

	if (MathHelper::IsPointInCircle((FLOAT)PlayerV->X, (FLOAT)PlayerV->Y, (FLOAT)MonsterV->X, (FLOAT)MonsterV->Y))
	{
		std::list<Entity>::const_iterator iterator;
		
		for (iterator = b->MonsterList.begin(); iterator != b->MonsterList.end(); ++iterator)
		{
			UINT32 ID = iterator._Ptr->_Myval.GetEntityID();
			if (ID == e->GetEntityID())
				IsInList = TRUE;			
		}

		if (IsInList == FALSE)
		{
			if (e->GetEntityID() != 0)
			{
				Entity AddedMob = Entity();
				AddedMob.SetInfo(e->GetMemoryAddress());

				b->MonsterList.push_back(AddedMob);

				if (b->MonsterTrackingThread == NULL && b->isTrackingMonsters)
				{
					b->MonsterTrackingThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&MappingBot::HandleNearbyMonsters, 0, 0, 0);
				}
			}
		}
	}

	delete PlayerV;
	delete MonsterV;
	delete LocalEnt;
	PlayerV = nullptr;
	MonsterV = nullptr;
	LocalEnt = nullptr;
}


VOID MappingBot::HandleNearbyMonsters()
{
	MappingBot* mb = (MappingBot*)BotInstance->GetInstance();

	while (1)
	{
		if (mb->MonsterList.size() > 0)
		{
			std::list<Entity>::const_iterator iterator;
			for (iterator = mb->MonsterList.begin(); iterator != mb->MonsterList.end(); ++iterator)
			{
				Entity* e = LocalActor::GetEntityFromCharacterBasePtr();
			
				Vector2* v2 = Entity::GetEntityGridPosition(&iterator._Ptr->_Myval);
				Vector2 pV2 = e->GetVector2();
				
				if (v2 != NULL)
				{
					if ((v2->X == 0 || v2->Y == 0))
					{
						delete v2;
						delete e;
						e = nullptr; v2 = nullptr;
						iterator = mb->MonsterList.erase(iterator);
						continue;
					}

					if (MathHelper::IsPointInCircle((FLOAT)pV2.X, (FLOAT)pV2.Y, (FLOAT)v2->X, (FLOAT)v2->Y, 35.0f))
					{
						INT32 HP = Life::GetCurrentHP(&iterator._Ptr->_Myval);

						bool isTargetable = Targetable::GetIsTargetable(&iterator._Ptr->_Myval);
						
						if (isTargetable)
						{
							if (HP > 0 && !mb->isLooting)
							{
								mb->isAttacking = TRUE;
								mb->GetActor()->SendActionAndWaitForCooldown(0x2909, 0, v2);

								while ((HP > 0 && HP < 1000000) && isTargetable)
								{
									Vector2* v2_2 = Entity::GetEntityGridPosition(&iterator._Ptr->_Myval);
									if (v2_2 != NULL)
									{
										int Distance = MathHelper::GetDistanceBetweenObjects(pV2.X, pV2.Y, v2_2->X, v2_2->Y);
										printf("Distance between monster: %d\n", Distance);
										if (Distance <= 70)
										{
											mb->GetActor()->SendActionAndWaitForCooldown(mb->MainAttackSkillID, 0, v2_2); //change from hardcoded to user input/profile file
											HP = Life::GetCurrentHP(&iterator._Ptr->_Myval);
											isTargetable = Targetable::GetIsTargetable(&iterator._Ptr->_Myval);
										}
										else
										{
											mb->isAttacking = FALSE;
											delete v2_2;
											v2_2 = nullptr;
											iterator = mb->MonsterList.erase(iterator);
											continue;
										}
									}
									delete v2_2;
									v2_2 = nullptr;
								}
								mb->isAttacking = FALSE;
							}						
						}
						iterator = mb->MonsterList.erase(iterator);
					}
					delete v2;
					delete e;
					e = nullptr; v2 = nullptr;
				}
				else
				{
					delete v2;
					delete e;
					e = nullptr; v2 = nullptr;
					iterator = mb->MonsterList.erase(iterator);
				}				
			}
		}
	}
		
	mb->MonsterTrackingThread = NULL;
}

VOID MappingBot::MonitorCharacterHealthMana() //thread func
{
	while (1) //change this to while 'botting' or some variation
	{
		Entity* ent = LocalActor::GetEntityFromCharacterBasePtr(); //we need this in a loop as changing maps will shift the mem. addr of your entity.
			
		if (ent != NULL)
		{
			//read hp + mp, use flasks accordingly
			INT32 CurrentHP = Life::GetCurrentHP(ent);
			INT32 MaxHP = Life::GetMaxHP(ent);

			if (MaxHP == 0)
				continue;

			//divide current by max to check %, if below some value use flask
			FLOAT Percentage = (FLOAT)CurrentHP / (FLOAT)MaxHP;

			if (Percentage <= 0.50f) //meh 45% 
			{
				printf("Using life flask!\n");
				LocalActor::UseFlask(0); //make this user-input for slot after testing
				Sleep(1000);
			}

			INT32 CurrentMP = Life::GetCurrentMP(ent);

			if (CurrentMP <= 50)
			{
				printf("Using mana flask!\n");
				LocalActor::UseFlask(1); //make this user-input for slot after testing
				Sleep(1000);
			}

			if (CurrentHP == 0) //dead! set action ID to dead and packet to revive to checkpt or town
			{
				printf("Reviving in Town...\n");
				Sleep(3000);
				LocalActor::ReviveCharacterOnDeath(1);
				Sleep(3000);
			}
		}

		delete ent;
		ent = nullptr;
		Sleep(100);
	}
}

VOID MappingBot::HandleCurrentHPMP()
{
	static int Count = 0; //Because the ASM hook loops twice over this

	MappingBot* mb = (MappingBot*)BotInstance->GetInstance();

	if (GetKeyState(VK_F2) & 0x8000) //traverse thru registered hotkeys
	{
		Count += 1;

		if (Count >= 2)
		{
			Count = 0;
			Entity* e = mb->GetActor()->GetEntityFromCharacterBasePtr();
			Vector2* Pos = Entity::GetEntityGridPosition(e);
			LocalActor::UseFlare(Pos);
			delete e;
			delete Pos;
			e = nullptr;
			Pos = nullptr;
		}

		printf("F2 pressed!\n");
	}

	if (GetKeyState(VK_F3) & 0x8000) //traverse thru registered hotkeys
	{
		Count += 1;

		if (Count >= 2)
		{
			Count = 0;
			Entity* e = mb->GetActor()->GetEntityFromCharacterBasePtr();
			Vector2* Pos = Entity::GetEntityGridPosition(e);
			Pos->X += 50;
			Pos->Y += 50;
			LocalActor::UseDynamite(Pos);
			delete e;
			delete Pos;
			e = nullptr;
			Pos = nullptr;
		}
		printf("F3 pressed!\n");
	}
}

VOID MappingBot::HandleAreaTransition(Entity* e) //todo: Get 
{
	MappingBot* mb = (MappingBot*)BotInstance->GetInstance();
	
	UINT16 Area = AreaTransition::GetAreaID(e);
	byte AreaType = AreaTransition::GetTransitionType(e);

	if (Area == mb->ActorPath->GetDestinationArea() && mb->ActorPath->GetPathDirection() != Directions::NONE)
	{
		//send interaction
		mb->AreaTransitionID = e->GetEntityID();
		mb->ActorPath->SetPathDirection(Directions::AREA_TRANSITION);
	}

	wprintf(L"Area Transition, Location: (%d,%d), AreaID: %d, TransitionType: %d\n", e->GetVector2().X, e->GetVector2().Y, Area, AreaType);
	wprintf(L"==================================================\n");
}


VOID MappingBot::InitializeAreaMappings() //finish this shit
{
	for (int i = 0; i < 255; i++)	
		AreaMappings[i] = "";
	

	AreaMappings[1] = "Lioneye's Watch";
	AreaMappings[2] = "??";
	AreaMappings[3] = "The Coast";
	AreaMappings[4] = "The Tidal Island";
	AreaMappings[5] = "The Mud Flats";
	AreaMappings[6] = "The Fetid Pool";
	AreaMappings[7] = "??";
	AreaMappings[8] = "The Submerged Passage";
	AreaMappings[9] = "The Ledge";
	AreaMappings[10] = "The Climb";
	AreaMappings[11] = "The Lower Prison";
	AreaMappings[12] = "The Upper Prison";
	AreaMappings[13] = "Prisoner's Gate";
	AreaMappings[14] = "The Ship Graveyard";
	AreaMappings[15] = "The Ship Graveyard Cave";
	AreaMappings[16] = "The Cavern Of Wrath";
	AreaMappings[18] = "The Forst Encampment";
	AreaMappings[19] = "The Southern Forest";


	AreaMappings[132] = "The Blood Aqueduct";
	AreaMappings[133] = "Highgate"; //FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
}

std::string MappingBot::GetMapNameByIndex(int index)
{
	return AreaMappings[index];
}

int MappingBot::GetMapIndexByName(std::string name)
{
	for (int i = 0; i < 255; i++) //change to sizeof aremapping array
	{
		if (name.compare(AreaMappings[i]) == 0)
			return i;
	}

	return 0;
}

VOID DecideDestination(Directions CurrentDirection, Directions DestinationDirection)
{



}
#include "ObjectMagicProperties.hpp"

MonsterQuality ObjectMagicProperties::GetQuality(Entity* e)
{
	MonsterQuality quality;
	UINT64 OMPComponentAddr = e->GetComponentAddress("ObjectMagicProperties");

	if (OMPComponentAddr != 0)
	{
		quality = *(MonsterQuality*)(OMPComponentAddr + 0x7C);
		this->MobQuality = quality;
		return quality;
	}

	return MonsterQuality::Normal;
}

VOID ObjectMagicProperties::FillPropertiesList(Entity* e)
{
	std::wstring attribute;
	UINT64 ListStart = 0;
	UINT64 ListEnd = 0;

	UINT64 OMPComponentAddr = e->GetComponentAddress("ObjectMagicProperties");

	if (OMPComponentAddr != 0)
	{
		ListStart = *(UINT64*)(OMPComponentAddr + 0x98);
		ListEnd = *(UINT64*)(OMPComponentAddr + 0xA0);
	
		if (ListStart == 0 || ListEnd == 0)
			return;

		for (UINT64 i = ListStart; i < ListEnd; i += 0x28)
		{
			UINT64 AttributeAddr = i + 0x20;
			AttributeAddr = *(UINT64*)AttributeAddr;
			wprintf(L"Attribute: %s\n", AttributeAddr);
			
			//this->Properties->push_back(attribute);
		}

	}

}
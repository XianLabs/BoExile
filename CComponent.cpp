#include "CComponent.hpp"

CComponent::CComponent(UINT64 Address, UINT64 ListNodeAddress)
{
	this->ComponentMemoryAddress = Address;
	this->ComponentListNodeAddress = ListNodeAddress;
}
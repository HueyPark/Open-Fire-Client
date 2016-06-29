// Free to use

#include "OpenFire.h"
#include "BuildingData.h"

BuildingData::BuildingData(int32 buildingID, int32 strongPointID)
{
	this->buildingID = buildingID;
	this->strongPointID = strongPointID;
	this->type = ObjectDataType::Building;
}

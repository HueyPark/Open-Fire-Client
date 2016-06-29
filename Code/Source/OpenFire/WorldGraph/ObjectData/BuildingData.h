// Free to use

#pragma once

#include "ObjectData.h"

class OPENFIRE_API BuildingData : public ObjectData
{
public:
	int32 buildingID;

public:
	BuildingData(int32 buildingID, int32 strongPointID);
};

// Free to use

#pragma once

class ObjectData;
class BuildingData;
class ResourceData;

class OPENFIRE_API StrongPointData
{
public:
	int32 strongPointID;
	FVector location;

private:
	BuildingData* buildingData = nullptr;

public:
	StrongPointData(int32 id, FVector location)
	{
		this->strongPointID = id;
		this->location = location;
	};
};

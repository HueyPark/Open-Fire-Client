// Free to use

#pragma once

class ObjectData;
class BuildingData;
class ResourceData;

namespace World
{

class OPENFIRE_API Strongpoint
{
public:
	FString id;
	FVector location;

private:
	BuildingData* buildingData = nullptr;

public:
	Strongpoint(const FString id, const FVector location)
	{
		this->id = id;
		this->location = location;
	};
};

}

// Free to use

#pragma once

class ObjectData;
class BuildingData;
class ResourceData;
enum class Request;

namespace World
{

class OPENFIRE_API Strongpoint
{
public:
	FString id;
	FVector location;
	int32 level;
	Request request;

private:
	BuildingData* buildingData = nullptr;

public:
	Strongpoint(const FString id, const FVector location, const int32 level, const Request request);	
};

}

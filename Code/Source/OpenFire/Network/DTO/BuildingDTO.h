// Free to use

#pragma once

class BuildingDTO
{
public:
	struct Data
	{
		int32 buildingID = -1;
		int32 strongPointID = -1;
	};

public:
	TArray<Data> datas;

public:
	BuildingDTO(const FString& string);
};
// Free to use

#pragma once

namespace DTO
{

class Island
{
public:
	struct Strongpoint
	{
		FString id = "";
		FVector location = FVector::ZeroVector;
		int32 level = 0;
	};

public:
	TArray<Strongpoint> strongpoints;

public:
	Island(const FString& string);
};

}

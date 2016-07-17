// Free to use

#pragma once

enum class Request;

namespace DTO
{

class Island
{
public:
	struct Strongpoint
	{
		FString id;
		FVector location;
		int32 level;
		Request request;
	};

public:
	TArray<Strongpoint> strongpoints;

public:
	Island(const FString& string);
};

}

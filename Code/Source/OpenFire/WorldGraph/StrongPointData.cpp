// Free to use

#include "OpenFire.h"
#include "StrongPointData.h"

namespace World
{

Strongpoint::Strongpoint(const FString id, const FVector location, const int32 level, const Request request)
{
	this->id = id;
	this->location = location;
	this->level = level;
	this->request = request;
}

}

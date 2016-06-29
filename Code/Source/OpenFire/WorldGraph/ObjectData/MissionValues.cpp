// Free to use

#include "OpenFire.h"
#include "MissionValues.h"
#include "Type/MissionType.h"

MissionValues::MissionValues()
{

}

MissionValues::MissionValues(int32 redValue, int32 greenValue, int32 blueValue)
{
	this->redValue = redValue;
	this->greenValue = greenValue;
	this->blueValue = blueValue;
}

const FLinearColor MissionValues::GetColor() const
{
	FLinearColor color = MissionType::Red * this->redValue + MissionType::Green * this->greenValue + MissionType::Blue * this->blueValue;
	int32 valueSum = this->redValue + this->greenValue + this->blueValue;

	return color / valueSum;
}

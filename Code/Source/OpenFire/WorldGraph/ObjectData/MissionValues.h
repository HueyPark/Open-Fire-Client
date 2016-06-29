// Free to use

#pragma once

class MissionValues
{
private:
	int32 redValue = -1;
	int32 greenValue = -1;
	int32 blueValue = -1;

public:
	MissionValues();
	MissionValues(int32 redValue, int32 greenValue, int32 blueValue);

	const FLinearColor GetColor() const;
};

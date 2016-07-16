// Free to use

#include "OpenFire.h"
#include "IslandDTO.h"

namespace DTO
{

Island::Island(const FString& string)
{
	TSharedPtr<FJsonObject> JsonObject;

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(string);

	if(FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		const TArray<TSharedPtr<FJsonValue>>& strongPoints = JsonObject->GetArrayField("strongpoints");
		for(const TSharedPtr<FJsonValue>& strongPoint : strongPoints)
		{
			Strongpoint strongpoint;

			const TSharedPtr<FJsonObject>& jsonObject = strongPoint->AsObject();
			strongpoint.id = jsonObject->GetStringField("id");
			strongpoint.location.X = jsonObject->GetNumberField("x");
			strongpoint.location.Y = jsonObject->GetNumberField("y");
			strongpoint.level = jsonObject->GetIntegerField("level");

			strongpoints.Add(strongpoint);
		}
	}
}

}

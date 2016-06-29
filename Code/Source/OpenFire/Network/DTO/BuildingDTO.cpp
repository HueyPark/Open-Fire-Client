// Free to use

#include "OpenFire.h"
#include "BuildingDTO.h"

BuildingDTO::BuildingDTO(const FString& string)
{
	TSharedPtr<FJsonObject> JsonObject;

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(string);

	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		const TArray<TSharedPtr<FJsonValue>>& strongPoints = JsonObject->GetArrayField("buildings");
		for (const TSharedPtr<FJsonValue>& strongPoint : strongPoints)
		{
			Data data;

			const TSharedPtr<FJsonObject>& jsonObject = strongPoint->AsObject();
			data.buildingID = jsonObject->GetIntegerField("building_id");
			data.strongPointID = jsonObject->GetIntegerField("strongpoint_id");

			datas.Add(data);
		}
	}
}

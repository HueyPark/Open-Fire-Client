// Free to use

#include "OpenFire.h"
#include "StrongPointDTO.h"

StrongPointDTO::StrongPointDTO(const FString& string)
{
	TSharedPtr<FJsonObject> JsonObject;

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(string);

	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		const TArray<TSharedPtr<FJsonValue>>& strongPoints = JsonObject->GetArrayField("strongpoints");
		for (const TSharedPtr<FJsonValue>& strongPoint : strongPoints)
		{
			Data data;

			const TSharedPtr<FJsonObject>& jsonObject = strongPoint->AsObject();
			data.strongPointID = jsonObject->GetIntegerField("id");
			data.location.X = jsonObject->GetNumberField("location_x");
			data.location.Y = jsonObject->GetNumberField("location_y");

			datas.Add(data);
		}
	}
}

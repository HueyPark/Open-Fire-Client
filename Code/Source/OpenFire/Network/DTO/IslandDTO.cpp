// Free to use

#include "OpenFire.h"
#include "IslandDTO.h"
#include "Type/Request.h"

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
			strongpoint.location.Z = 0.0f;
			strongpoint.level = jsonObject->GetIntegerField("level");
			strongpoint.request = static_cast<Request>(jsonObject->GetIntegerField("request"));

			strongpoints.Add(strongpoint);
		}
	}
}

}

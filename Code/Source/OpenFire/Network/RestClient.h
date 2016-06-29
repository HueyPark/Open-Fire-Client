// Free to use

#pragma once

#include "Object.h"
#include <functional>
#include "Runtime/Online/HTTP/Public/Http.h"
#include "RestClient.generated.h"

UCLASS()
class OPENFIRE_API URestClient: public UObject
{
	GENERATED_BODY()

private:
	static URestClient* instance;

	std::function<void(const FString&)> endFunction = nullptr;

public:
	static URestClient* Instance();

	void Get(const FString& url, const FString& data, std::function<void(const FString&)> endFunction = nullptr);
	void Post(const FString& url, const FString& data, std::function<void(const FString&)> endFunction = nullptr);
	void Put(const FString& url, const FString& data, std::function<void(const FString&)> endFunction = nullptr);
	void Delete(const FString& url, const FString& data, std::function<void(const FString&)> endFunction = nullptr);

private:
	void Request(const FString& url, const FString& verb, const FString& data, std::function<void(const FString&)> endFunction);

	void OnResponseReceived(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);
};

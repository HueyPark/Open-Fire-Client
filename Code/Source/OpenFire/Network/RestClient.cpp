// Free to use

#include "OpenFire.h"
#include "RestClient.h"

URestClient* URestClient::instance = nullptr;

URestClient* URestClient::Instance()
{
	return NewObject<URestClient>(URestClient::StaticClass());
}

void URestClient::Get(const FString& url, const FString& data, std::function<void(const FString&)> endFunction /*= nullptr*/)
{
	this->Request(url, TEXT("GET"), data, endFunction);
}

void URestClient::Post(const FString& url, const FString& data, std::function<void(const FString&)> endFunction /*= nullptr*/)
{
	this->Request(url, TEXT("POST"), data, endFunction);
}

void URestClient::Put(const FString& url, const FString& data, std::function<void(const FString&)> endFunction /*= nullptr*/)
{
	this->Request(url, TEXT("PUT"), data, endFunction);
}

void URestClient::Delete(const FString & url, const FString & data, std::function<void(const FString&)> endFunction /*= nullptr*/)
{
	this->Request(url, TEXT("DELETE"), data, endFunction);
}

void URestClient::Request(const FString& url, const FString& verb, const FString& data, std::function<void(const FString&)> endFunction)
{
	TSharedRef<IHttpRequest> httpRequest = FHttpModule::Get().CreateRequest();

	httpRequest->OnProcessRequestComplete().BindUObject(this, &URestClient::OnResponseReceived);

	httpRequest->SetURL(url);
	httpRequest->SetVerb(verb);
	httpRequest->SetHeader("Content-Type", TEXT("application/json"));
	httpRequest->SetContentAsString(data);

	httpRequest->ProcessRequest();

	this->endFunction = endFunction;
}

void URestClient::OnResponseReceived(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	if (bWasSuccessful == true)
	{
		if (this->endFunction != nullptr)
		{
			this->endFunction(response->GetContentAsString());
			this->endFunction = nullptr;
		}
	}
}

#pragma once

template<typename T>
class OPENFIRE_API Singleton
{
public:
	static T* Instance()
	{
		static T instance;
		return &instance;
	}

protected:
	Singleton() { }
	Singleton(Singleton const&) {};
	Singleton& operator= (Singleton const&) { return *this; };
};
